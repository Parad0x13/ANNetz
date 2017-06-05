#include "ComponentManager.h"

using namespace std;
ComponentManager::ComponentManager(int inSize, int outSize, int Length) : inputSize(inSize), OutputSize(outSize) {
	components = vector<vector<Component*>>(Length);
	connections = vector<vector<Connection>>(Length - 1);
	ptVec = vector<PassThrough>(Length);

	for (int i = 0; i < Length; i++) {
		components[i] = vector<Component*>(1);
		ptVec[i] = PassThrough(1);
		components[i][0] = &ptVec[i];
	}

	for (int i = 0; i < Length - 1; i++) {
		connections[i] = vector<Connection>(1);
		connections[i][0] = Connection(0, components[i][0], components[i][0]);
	}
}

ComponentManager::~ComponentManager() {
}

std::vector<double> ComponentManager::calcOut(std::vector<double> input) {
	components[0][0]->calcOut(input);
	for (int i = 1; i < components.size(); i++) {
		for (int c = 0; c < connections[i - 1].size(); c++) {
			connections[i][c].indexB->calcOut(connections[i][c].indexA->output); // [TODO] change component class to allow combining inputVectors(with RefreshInput function)
		}
	}
	return components[components.size() - 1][0]->output;
}
