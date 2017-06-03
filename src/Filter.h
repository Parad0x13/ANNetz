#ifndef FILTER_H
#define FILTER_H

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
	void calcOut(std::vector<double>);
	void refreshInputSize(int, int);

private:
	int inX, inY;
	int outX, outY;
	int featureX, featureY;
	std::vector<double> feature;
	double calcTF(double);
};

#endif



