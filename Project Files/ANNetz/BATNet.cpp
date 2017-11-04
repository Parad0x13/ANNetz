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

void BATNet::render(string prefix) {
	cout << prefix << endl;
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
	BATLayer *previousLayer = NULL;
	if (layers.size() > 0) previousLayer = layers.back();

	BATLayer *layer = new BATLayer(nodeSize);
	layers.push_back(layer);

	if (previousLayer != NULL) {
		layer->setPreviousLayer(previousLayer);
	}
}

void BATNet::learn(int iterations) {
	for (int iter = 0;iter < iterations;iter++) {
		// First we setup the input layer nodes
		vector<double> dataPoint = classifyData[0];				// [TODO] Should be random
		// [TODO] Should add error checking here...
		BATLayer *layer = layers[0];
		int dataPointIndex = 0;
		for (BATNode *node : layer->nodes) {
			node->value = dataPoint[dataPointIndex++];
		}

		// Now we run everything through, feed-forward
	}
}