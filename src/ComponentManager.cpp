#include "ComponentManager.h"

using namespace std;
ComponentManager::ComponentManager(int inSize, int outSize, int Length) : inputSize(inSize), OutputSize(outSize) {
	components = vector<vector<Component*>>(Length);
	connections = vector<vector<Connection*>>(Length - 1);

	for (int i = 0; i < Length; i++) {
		components[i] = vector<Component*>(1);

		if(i == 0) components[i][0] = new PassThrough(inputSize);
		else {
			if (i == Length - 1) components[i][0] = new PassThrough(OutputSize);
			else components[i][0] = new PassThrough(1);
		}	
	}

	for (int i = 0; i < Length - 1; i++) {
		connections[i] = vector<Connection*>(1);
		connections[i][0] = new Connection(0, components[i][0], components[i + 1][0]);
	}
}

ComponentManager::~ComponentManager() {
}

std::vector<double*> ComponentManager::calcOut(std::vector<double*> input) {
	//set Input
	for (int i = 0; i < components[0].size(); i++) {
		components[0][i]->setInput(0, input);
		components[0][i]->calcOut();
	}

	//go through layerwise
	for (int i = 1; i < components.size(); i++) {
		//refresh all inputs;
		for (int c = 0; c < connections[i - 1].size(); c++) {
			connections[i - 1][c]->setInput();
		}
		//calc Outputs
		for (int c = 0; c < components[i].size(); c++) {
			components[i][c]->calcOut();
		}
	}
	return components[components.size() - 1][0]->output;
}

void ComponentManager::setComponent(Component * com, int layer, int index) {
	if (layer < components.size() - 1) { //not last layer 
		for (int j = 0; j < connections[layer].size(); j++) {
			if (connections[layer][j]->indexA == components[layer][index]) {
				connections[layer][j]->indexA = com;
			}
		}
	}
	if (layer != 0) { //not first layer 
		for (int j = 0; j < connections[layer - 1].size(); j++) {
			if (connections[layer - 1][j]->indexB == components[layer][index]) {
				connections[layer - 1][j]->indexB = com;
			}
		}
	}

	components[layer][index] = com;
}
