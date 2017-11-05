#include <iostream>
#include <iomanip>

#include "BATNode.h"
#include "BATLayer.h"
#include "Utility.h"

using namespace std;

BATNode::BATNode() {
	bias = 0;	// [TODO] Figure out when, why, and how I should set the bias value
	previousLayer = NULL;
}

BATNode::~BATNode() {
	//
}

void BATNode::render(string prefix) {
	cout << fixed << setprecision(3) << prefix << " activation:" << getActivation() << "\t\tbias:" << bias << endl;

	for (double weight : weights) {
		cout << "            [WEIGHT] " << weight << endl;		// [TODO] Get this to match indentation dynamically
	}
}

void BATNode::setPreviousLayer(BATLayer *layer) {
	weights.clear();

	previousLayer = layer;

	for (BATNode *previousNode : previousLayer->nodes) {
		double value = getRandomDouble(-1, 1);
		weights.push_back(value);
	}
}

// [TODO] Find a way to ensure this value gets cached when it doesn't need to be recalculated
// Otherwise it might get calculated several times for no reason
double BATNode::getActivation() {
	if (previousLayer == NULL) {
		// [TODO] Ensure that defaultValue never needs to rely on bias, otherwise it needs to be return defaultValue + bias;
		return defaultValue;
	}

	double cost = 0;
	for (int i = 0;i < previousLayer->nodes.size();i++) {
		BATNode *node = previousLayer->nodes[i];
		double a = node->getActivation();
		double w = weights[i];
		cost += a * w;
	}

	cost += bias;

	return sigmoid(cost);
}

double BATNode::sigmoid(double x) {
	// sigmoid(x) = 1 / (1 + e^-x)
	// I'm not going to use the actual sigmoid function here, instead I'm going to use a more simplified version of it
	// f(x) = x / (1 + abs(x))		https://stackoverflow.com/questions/10732027/fast-sigmoid-algorithm

	return x / (1.0 + abs(x));
}
