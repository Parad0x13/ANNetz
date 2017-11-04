#pragma once
#include <string>

class BATNet {
public:
	BATNet();
	~BATNet();

	void setClassifier(std::string, int, int);		// Assumes dataPoints preceed classIndex
	// Need start layer
	// Need hidden layer
	// Need end layer
	// Need correct terms for these..
	// Each node has a bias
	// Each node needs a random value assigned to them
	// First test is to build a classifier for irisData.txt
	// irisData.txt is broken in to petalLength1, petalLength2, petalLength3, petalLength4, irisClassIndex
};
