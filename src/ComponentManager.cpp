#include "ComponentManager.h"

using namespace std;

ComponentManager::ComponentManager(int inSize, int outSize, int Length) : inputSize(inSize), OutputSize(outSize) {
	components = vector<vector<Component*>>(Length);
	connections = vector<vector<Connection*>>(Length - 1);

	for (int i = 0; i < Length; i++) {
		components[i] = vector<Component*>(1);

		if(i == 0) components[i][0] = new Passthrough(inputSize);
		else {
			if (i == Length - 1) components[i][0] = new Passthrough(OutputSize);
			else components[i][0] = new Passthrough(1);
		}	
	}

	for (int i = 0; i < Length - 1; i++) {
		connections[i] = vector<Connection*>(1);
		connections[i][0] = new Connection(0, components[i][0], components[i + 1][0]);
	}
}

ComponentManager::~ComponentManager() {
	//
}

std::vector<double*> ComponentManager::calcOut(std::vector<double*> input) {
	// Set Input
	for (int i = 0; i < components[0].size(); i++) {
		components[0][i]->setInput(0, input);
		components[0][i]->calcOut();
	}

	// Go through layerwise
	for (int i = 1; i < components.size(); i++) {
		// Refresh all inputs;
		for (int c = 0; c < connections[i - 1].size(); c++) {
			connections[i - 1][c]->setInput();
		}

		// Calc Outputs
		for (int c = 0; c < components[i].size(); c++) {
			components[i][c]->calcOut();
		}
	}
	return components[components.size() - 1][0]->output;
}

void ComponentManager::setComponent(Component * com, int layer, int index) {
	if (layer < components.size() - 1) {	// Not last layer 
		for (int j = 0; j < connections[layer].size(); j++) {
			if (connections[layer][j]->indexA == components[layer][index]) {
				connections[layer][j]->indexA = com;
			}
		}
	}

	if (layer != 0) {	// Not first layer 
		for (int j = 0; j < connections[layer - 1].size(); j++) {
			if (connections[layer - 1][j]->indexB == components[layer][index]) {
				connections[layer - 1][j]->indexB = com;
			}
		}
	}

	components[layer][index] = com;
}

void ComponentManager::getDataSet(std::string path) {
	//BMP image;
	//image.ReadFromFile((path + "\\0.bmp").c_str());

	// START OF HIS CODE
	string line;
	vector<string> outs;
	// Read IndexFile
	ifstream myfile(path + "\\index.txt");
	if (myfile.is_open()) {
		getline(myfile, line);
		// [TODO] Switch here the data types 
		getline(myfile, line);
		outs = splitString(line, ';');
		myfile.close();
	}
	else error("Unable to open file");

	targets = vector<vector<double*>>(outs.size());
	inputs = vector<vector<double*>>(outs.size());

	for (int i = 0; i < outs.size(); i++) {
		targets[i] = vector<double*>(1);	// Change that later!
		inputs[i] = vector<double*>(1);

		targets[i][0] = new double(std::stod(outs[i]));
	}

	// Read InputData
	for (int i = 0; i < outs.size(); i++) {
		stringstream ss;
		ss << i;
		cout << i << ".bmp" << endl;
		inputs[i] = BMToArray(path + "\\" + ss.str() + ".bmp");
	}
}

std::vector<double*> ComponentManager::BMToArray(std::string path) {
	vector<char> bytes = readFileBytes(path);
	vector<double*> ret;
	int offset = 54;

	for (int i = offset; i < bytes.size(); i++) {
		int val = (int)bytes[i];
		if (val < 0) val = 256 + val;
		ret.push_back(new double(1.0 / val));
	}

	for (int y = 3; y >= 0; y--) {
		for (int x = 0; x < 4; x++) {
			cout << "{" << getHex(bytes[offset + (x + 4 * y) * 3 + 0]) << "," << getHex(bytes[offset + (x + 4 * y) * 3 + 1]) << "," << getHex(bytes[offset + (x + 4 * y) * 3 + 2]) << "}";
		}
		cout << endl;
	}

	return ret;
}
