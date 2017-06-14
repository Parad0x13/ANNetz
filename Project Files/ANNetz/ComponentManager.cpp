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

vector<double*> ComponentManager::calcOut(vector<double*> input) {
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

void ComponentManager::setComponent(Component* com, int layer, int index) {
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
	string line;
	vector<string> outs;
	vector<string> buffer;
	int DataMode = 0; // BMP, BinaryData
	// Read IndexFile
	ifstream myfile(path + "\\index.txt");
	if (myfile.is_open()) {
		getline(myfile, line);
		if (line == "bmp") {
			DataMode = 0;
		}
		else {}
		// [TODO] Switch here the data types 
		getline(myfile, line);
		outs = splitString(line, ';');
		inputSize = std::stoi(outs[0]);
		OutputSize = std::stoi(outs[1]);

		getline(myfile, line);
		outs = splitString(line, ';');

		myfile.close();
	}
	else error("Unable to open file");

	targets = vector<vector<double*>>(outs.size());
	inputs = vector<vector<double*>>(outs.size());

	for (int i = 0; i < outs.size(); i++) {
		targets[i] = vector<double*>(OutputSize);	// Change that later!
		inputs[i] = vector<double*>(inputSize);

		buffer = splitString(outs[i], '#'); //for multiLayer output
		for (int j = 0; j < buffer.size(); j++) {
			targets[i][0] = new double(std::stod(buffer[j]));
		}
	}

	// Read InputData
	if (DataMode == 0) {
		for (int i = 0; i < outs.size(); i++) {
			stringstream ss;
			ss << i;
			cout << i << ".bmp" << endl;
			inputs[i] = BMToArray(path + "\\" + ss.str() + ".bmp", BmChannelFilter::GrayScale);
		}
	}

}

std::vector<double*> ComponentManager::BMToArray(std::string path, BmChannelFilter bmc) {
	vector<double*> retVal;

	BMP image;
	image.ReadFromFile(path.c_str());

	switch (bmc)
	{
	case 0: //Raw RGB		useless?
		for (int y = 0; y < image.TellHeight(); y++) {
			for (int x = 0; x < image.TellWidth(); x++) {
				double value1 = image(x, y)->Red / 255.0;
				retVal.push_back(&value1);
				double value2 = image(x, y)->Green / 255.0;
				retVal.push_back(&value2);
				double value3 = image(x, y)->Blue / 255.0;
				retVal.push_back(&value3);
			}
		} break;
	case 1: //Sorted RGB
		for (int i = 0; i < 3; i++) {
			for (int y = 0; y < image.TellHeight(); y++) {
				for (int x = 0; x < image.TellWidth(); x++) {
					double value = 0;
					switch (i)
					{
					case 0: value = image(x, y)->Red / 255.0; break;
					case 1: value = image(x, y)->Green / 255.0; break;
					case 2: value = image(x, y)->Blue / 255.0; break;
					}
					retVal.push_back(&value);
				}
			}
		}
		break;
	case 2: //GrayScale
		for (int y = 0; y < image.TellHeight(); y++) {
			for (int x = 0; x < image.TellWidth(); x++) {
				double value = (image(x, y)->Red + image(x, y)->Green + image(x, y)->Blue) / 765.0; //255 * 3 = 765
				retVal.push_back(&value);
			}
		} break;
	case 3: //human grayScale
		for (int y = 0; y < image.TellHeight(); y++) {
			for (int x = 0; x < image.TellWidth(); x++) {
				double value = (image(x, y)->Red * 0.30 + image(x, y)->Green *0.59 + image(x, y)->Blue * 0.11) / 765.0; //255 * 3 = 765
				retVal.push_back(&value);
			}
		}
		break;
	}

	return retVal;
}
