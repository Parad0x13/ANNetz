#include <iostream>
#include <vector>

#include "BATNet.h"
#include "Utility.h"

using namespace std;

BATNet::BATNet() {
	//
}

BATNet::~BATNet() {
	//
}

void BATNet::render() {
	for (BATLayer *layer : layers) {
		layer->render();
	}
}

void BATNet::setDataToClassify(string filename, int dataPointCount, int classIndex) {
	vector<vector<string>> data = dataFromCSV(filename);

	for (vector<string> line : data) {
		vector<double> lineData;
		for (string dataPointAndIndex : line) {
			double value = stod(dataPointAndIndex);
			lineData.push_back(value);
		}
		classifyData.push_back(lineData);
	}
}

void BATNet::addLayer(int nodeSize) {
	BATLayer *layer = new BATLayer(nodeSize);
	layers.push_back(layer);
}