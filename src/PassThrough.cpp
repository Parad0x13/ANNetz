#include "PassThrough.h"



PassThrough::PassThrough() {
}

PassThrough::PassThrough(int inSize) : inputSize(inSize) {
}

PassThrough::~PassThrough() {
}

void PassThrough::calcOut(std::vector<double> input) {
	output = input;
}
