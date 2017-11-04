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
	cout << "Learning..." << endl;
	for (int iter = 0;iter < iterations;iter++) {
		// First we setup the input layer nodes
		vector<double> dataPoint = classifyData[getRandomInt(0, classifyData.size() - 1)];
		int correctClassificationIndex = dataPoint.back();
		// [TODO] Should add error checking here...
		BATLayer *firstLayer = layers.front();
		int dataPointIndex = 0;
		for (BATNode *node : firstLayer->nodes) {
			node->defaultValue = dataPoint[dataPointIndex++];
		}

		// Now we run everything through, feed-forward
		double highestActivation = 0;
		int highestActivationIndex = -1;

		BATLayer *lastLayer = layers.back();
		for (int i = 0; i < lastLayer->nodes.size();i++) {
			BATNode *node = lastLayer->nodes[i];
			double activation = node->getActivation();
			if (activation > highestActivation) {
				highestActivation = activation;
				highestActivationIndex = i;
			}
			cout << activation << endl;
		}

		if (highestActivationIndex == correctClassificationIndex) {
			cout << "Network found the correct answer!" << endl;
		}
		else {
			cout << "Network did not find the correct answer : (" << endl;
		}

		// Now we need to perform back propagation to re-enforce the network
	}
}