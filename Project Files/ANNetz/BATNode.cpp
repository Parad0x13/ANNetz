#include <iostream>
#include <iomanip>

#include "BATNode.h"
#include "BATLayer.h"
#include "Utility.h"

using namespace std;

BATNode::BATNode() {
	value = getRandomDouble(0, 1);
	bias = getRandomDouble(0, 1);
	previousLayer = NULL;
}

BATNode::~BATNode() {
	//
}

void BATNode::render(string prefix) {
	cout << fixed << setprecision(3) << prefix << " value:" << value << "\t\tbias:" << bias << endl;

	for (double weight : weights) {
		cout << "            [WEIGHT] " << weight << endl;		// [TODO] Get this to match indentation dynamically
	}
}

void BATNode::setPreviousLayer(BATLayer *layer) {
	weights.clear();

	previousLayer = layer;

	for (BATNode *previousNode : previousLayer->nodes) {
		weights.push_back(getRandomDouble(0, 1));
	}
}