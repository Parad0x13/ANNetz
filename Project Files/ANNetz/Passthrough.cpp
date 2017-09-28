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

std::vector<SimpleVertex> Passthrough::getVertices() {
	std::vector<SimpleVertex> ret = std::vector<SimpleVertex>(3);

	ret[0] = { XMFLOAT3(-0.5f, 0, 0), XMFLOAT2(0.0f, 0.0f) };
	ret[1] = { XMFLOAT3(0, 0.866f, 0), XMFLOAT2(1.0f, 0.0f) };
	ret[2] = { XMFLOAT3(0.5f, 0, 0), XMFLOAT2(0.0f, 1.0f) };

	return ret;
}

std::vector<short> Passthrough::getIndices() {
	return std::vector<short>();
}
