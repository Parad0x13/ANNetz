#include "Filter.h"
#include <math.h>

Filter::Filter(TransferFunction _tf, std::vector<double> _feature, int _inX, int _inY, int fx, int fy)
{
	TF = _tf;
	featureX = fx; featureY = fy;
	feature = _feature;

	if (feature.size() != featureX * featureY) throw new std::exception("FeatureSize dont match frameSize");

	refreshInputSize(_inX, _inY);
}


Filter::~Filter()
{

}

void Filter::calcOut(std::vector<double> input)
{
	double buffer;
	//moving feature frame
	for (int x = 0; x < outX; x++) {
		for (int y = 0; y < outY; y++) {
			buffer = 0;
			
			//sum up featureFrame at this position
			for (int fx = 0; fx < featureX; fx++) {
				for (int fy = 0; fy < featureX; fy++) {
					buffer += calcTF(input[x + fx + (y + fy) * inX] - feature[fx + fy * featureX]);
				}
			}

			output[x + outX * y] = buffer / feature.size();
		}
	}
}

void Filter::refreshInputSize(int _inX, int _inY)
{
	inX = _inX, inY = _inY;
	if (featureX > inX || featureY > inY) throw new std::exception("FeatureSize is bigger then the InputSize");
	outX = inX - featureX + 1;
	outY = inY - featureY + 1;
	output = std::vector<double>(outX * outY);
}

double Filter::calcTF(double x)
{
	//functions zero points on (+-1, 0) and maxima at (0, 1)
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
