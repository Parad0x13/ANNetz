#include "Pooling.h"
#include <math.h>



Pooling::Pooling(int _inX, int _inY)
{
	refreshInputSize(_inX, _inY);
}

Pooling::~Pooling()
{
}

void Pooling::calcOut(std::vector<double> input)
{
	double buffer;
	//moving feature frame
	for (int x = 0; x < outX; x++) {
		for (int y = 0; y < outY; y++) {
			buffer = 0;

			//sum up featureFrame at this position
			for (int fx = 0; fx < 2; fx++) {
				if (fx + x < inX) {
					for (int fy = 0; fy < 2; fy++) {
						if (fy + y < inY) {
							buffer = fmax(input[x + fx + (y + fy) * inX], buffer);
						}					
					}
				}
			}

			output[x + outX * y] = buffer;
		}
	}
}

void Pooling::refreshInputSize(int _inX, int _inY)
{
	inX = _inX; inY = _inY;

	outX = (inX + 1) / 2;
	outY = (inY + 1) / 2;

	output = std::vector<double>(outX * outY);
}