#pragma once
#include <vector>

class BATNode {
public:
	BATNode();
	~BATNode();

	void render();

	double value, weight, bias;
};
