#pragma once
#include <vector>

class BATLayer;

class BATNode {
public:
	BATNode();
	~BATNode();

	void render(std::string prefix = "        [BATNode]");
	void setPreviousLayer(BATLayer *layer);
	double sigmoid(double x);
	double getActivation();

	// [TODO] Find out if I have to normalize defaultValue or not, or if not where the heck do I actually have to normalize data?
	double defaultValue, bias;
	std::vector<double> weights;
	BATLayer *previousLayer;
};
