#include <iostream>
#include <iomanip>

#include "BATNode.h"
#include "Utility.h"

using namespace std;

BATNode::BATNode() {
	value = getRandomDouble(0, 1);
	weight = getRandomDouble(0, 1);
	bias = getRandomDouble(0, 1);
}

BATNode::~BATNode() {
	//
}

void BATNode::render(string prefix) {
	cout << fixed << setprecision(3) << prefix << " value:" << value << "\t\tweight: " << weight << "\t\tbias:" << bias << endl;
}