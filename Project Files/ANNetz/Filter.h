#pragma once

#include <vector>
#include <string>

#include "Component.h"

class Filter : public Component {
public:
	enum TransferFunction {
		Linear, Eliptic, Exponential, Hyperbola
	};

	Filter(TransferFunction, std::vector<double>, int, int, int, int);
	~Filter();

	TransferFunction TF;
	void calcOut();

	//DX
	std::vector<SimpleVertex> getVertices();
	std::vector<short> getIndices();

	void refreshInputSize(int, int);

private:
	int inX, inY;
	int outX, outY;
	int featureX, featureY;
	std::vector<double> feature;
	double calcTF(double);
};
