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

void BATNet::setClassifier(string filename, int dataPointCount, int classIndex) {
	vector<vector<string>> data = dataFromCSV(filename);

	for (vector<string> line : data) {
		for (string dataPointAndIndex : line) {
			cout << dataPointAndIndex << " ";
		}
		cout << endl;
	}
}