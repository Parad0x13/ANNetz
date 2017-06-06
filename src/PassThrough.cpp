#include "PassThrough.h"
#include <vector>


PassThrough::PassThrough() {
}

PassThrough::PassThrough(int inSize) {
	inputSize = inSize;
	outputSize = inSize;

	input = std::vector<double*>(inputSize);
	input = std::vector<double*>(inputSize);
}

PassThrough::~PassThrough() {
}

void PassThrough::calcOut() {
	output = input;
}
