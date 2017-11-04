#pragma once
#include <vector>

class BATLayer;

class BATNode {
public:
	BATNode();
	~BATNode();

	void render(std::string prefix = "        [BATNode]");
	void setPreviousLayer(BATLayer *layer);

	double value, bias;
	std::vector<double> weights;
	BATLayer *previousLayer;
};
