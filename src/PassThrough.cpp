#include <vector>

#include "Passthrough.h"

Passthrough::Passthrough() {
	//
}

Passthrough::Passthrough(int inSize) {
	inputSize = inSize;
	outputSize = inSize;

	input = std::vector<double*>(inputSize);
	input = std::vector<double*>(inputSize);
}

Passthrough::~Passthrough() {
	//
}

void Passthrough::calcOut() {
	output = input;
}
