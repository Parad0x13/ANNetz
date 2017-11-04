#pragma once
#include <vector>

class BATNode {
public:
	BATNode();
	~BATNode();

	void render(std::string prefix = "        [BATNode]");

	double value, bias;
};
