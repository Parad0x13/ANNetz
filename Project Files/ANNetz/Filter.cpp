#include "Filter.h"
#include <math.h>

Filter::Filter(TransferFunction _tf, std::vector<double> _feature, int _inX, int _inY, int fx, int fy) {
	TF = _tf;
	featureX = fx; featureY = fy;
	feature = _feature;

	if (feature.size() != featureX * featureY) throw new std::exception("FeatureSize dont match frameSize");

	refreshInputSize(_inX, _inY);
}

Filter::~Filter() {
	//
}

void Filter::calcOut() {
	double buffer;
	// Moving feature frame
	for (int x = 0;x < outX;x++) {
		for (int y = 0;y < outY;y++) {
			buffer = 0;
			
			// Sum up featureFrame at this position
			for (int fx = 0;fx < featureX;fx++) {
				for (int fy = 0;fy < featureX;fy++) {
					buffer += calcTF(*input[x + fx + (y + fy) * inX] - feature[fx + fy * featureX]);
				}
			}

			output[x + outX * y] = new double(buffer / feature.size());
		}
	}
}

std::vector<SimpleVertex> Filter::getVertices() {
	std::vector<SimpleVertex> ret = std::vector<SimpleVertex>(3);

	ret[0] = { XMFLOAT3(-0.5f, 0, 0), XMFLOAT2(0.0f, 0.0f) };
	ret[1] = { XMFLOAT3(0, 0.866f, 0), XMFLOAT2(1.0f, 0.0f) };
	ret[2] = { XMFLOAT3(0.5f, 0, 0), XMFLOAT2(0.0f, 1.0f) };

	return ret;
}

std::vector<short> Filter::getIndices() {
	std::vector<short> ret = std::vector<short>(3);
	ret[0] = 0;
	ret[1] = 1;
	ret[2] = 2;

	return ret;
}

void Filter::refreshInputSize(int _inX, int _inY) {
	inX = _inX, inY = _inY;
	if (featureX > inX || featureY > inY) throw new std::exception("FeatureSize is bigger then the InputSize");

	inputSize = inX * inY;
	outX = inX - featureX + 1;
	outY = inY - featureY + 1;

	outputSize = outX * outY;
	output = std::vector<double*>(outputSize);
	input = std::vector<double*>(inputSize);
}

double Filter::calcTF(double x) {
	// Functions zero points on (+-1, 0) and maxima at (0, 1)
	// [TODO] Remove arbitrary value calculation, instead do case Linear:, case: Eliptic, etc...
	switch (TF) {
	case 0: // Linear
		return 1 - abs(x);
	case 1: // Eliptic
		return 1 - sqrt(1 - (abs(x) - 1) * (abs(x) - 1));
	case 2: //Exponential (Normal distribution) with Inflection points on +-0.5 and 
		return (exp(- x * x * 2) - exp(-2)) * exp(2) / (exp(2) - 1);
	case 3: //Hyperbola
		return 2 / (abs(x) + 1) - 1;
	}
	return 0;
}
