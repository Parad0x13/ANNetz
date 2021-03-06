#include <iostream>

#include "BATLayer.h"
#include "Utility.h"

using namespace std;

BATLayer::BATLayer(int nodeSize) {
	for (int d = 0;d < nodeSize;d++) {
		BATNode *node = new BATNode();
		nodes.push_back(node);
	}
}

BATLayer::~BATLayer() {
	//
}

void BATLayer::render(string prefix) {
	cout << prefix << endl;
	for (BATNode *node : nodes) {
		node->render();
	}
}

void BATLayer::setPreviousLayer(BATLayer *layer) {
	for (BATNode *node : nodes) {
		node->setPreviousLayer(layer);
	}
}
