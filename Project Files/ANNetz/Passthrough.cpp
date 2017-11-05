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

	textureID = 2;
}

Passthrough::~Passthrough() {
	//
}

void Passthrough::calcOut() {
	output = input;
}

std::vector<SimpleVertex> Passthrough::getVertices() {
	std::vector<SimpleVertex> ret = std::vector<SimpleVertex>(4);

	ret[0] = { XMFLOAT3(-0.5f, -0.5f, 0), XMFLOAT2(0.0f, 1.0f) };
	ret[1] = { XMFLOAT3(0.5f, -0.5f, 0), XMFLOAT2(1.0f, 1.0f) };
	ret[2] = { XMFLOAT3(-0.5f, 0.5f, 0), XMFLOAT2(0.0f, 0.0f) };
	ret[3] = { XMFLOAT3(0.5f, 0.5f, 0), XMFLOAT2(1.0f, 0.0f) };

	return ret;
}

std::vector<short> Passthrough::getIndices() {
	std::vector<short> ret = std::vector<short>{
		2, 1, 0,
		2, 3, 1
	};

	return ret;
}
