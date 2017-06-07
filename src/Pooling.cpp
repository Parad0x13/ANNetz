#include <math.h>

#include "Pooling.h"

Pooling::Pooling(int _inX, int _inY) {
	refreshInputSize(_inX, _inY);
}

Pooling::~Pooling() {
	//
}

void Pooling::calcOut() {
	double buffer;
	// Moving feature frame
	for (int x = 0; x < outX; x++) {
		for (int y = 0; y < outY; y++) {
			buffer = 0;

			// Sum up featureFrame at this position
			for (int fx = 0; fx < 2; fx++) {
				if (fx + x < inX) {
					for (int fy = 0; fy < 2; fy++) {
						if (fy + y < inY) {
							buffer = fmax(*input[x * 2 + fx + (y * 2 + fy) * inX], buffer);
						}					
					}
				}
			}

			output[x + outX * y] = new double(buffer);
		}
	}
}

void Pooling::refreshInputSize(int _inX, int _inY) {
	inX = _inX;
	inY = _inY;
	inputSize = inX * inY;

	outX = (inX + 1) / 2;
	outY = (inY + 1) / 2;

	outputSize = outX * outY;
	output = std::vector<double*>(outputSize);
	input = std::vector<double*>(inputSize);
}
