#include <iostream>

#include "BATLayer.h"
#include "Utility.h"

using namespace std;

BATLayer::BATLayer(int nodeSize) {
	for (int d = 0;d < nodeSize;d++) {
		BATNode *node = new BATNode();
		nodes.push_back(node);
		nextLayer = NULL;
	}
}

BATLayer::~BATLayer() {
	//
}

void BATLayer::render(string prefix) {
	cout << prefix << endl;
	for (BATNode *node : nodes) {
		node->render();

		int currentIndex = find(nodes.begin(), nodes.end(), node) - nodes.begin();
		if (weights.size() >= currentIndex + 1) {
			vector<double> currentWeights = weights[currentIndex];
			for (double weight : currentWeights) {
				cout << "            [WEIGHT] " << weight << endl;		// [TODO] Get this to match indentation dynamically
			}
		}
	}
}

void BATLayer::setNextLayer(BATLayer *layer) {
	nextLayer = layer;

	// [TODO] Make sure self.weights is empty first
	for (BATNode *node : nodes) {
		vector<double> nodeWeights;
		for (BATNode *otherNode : layer->nodes)
			nodeWeights.push_back(getRandomDouble(0, 1));
		weights.push_back(nodeWeights);
	}
}