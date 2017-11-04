#pragma once
#include <vector>

#include "BATNode.h"

class BATLayer {
public:
	BATLayer(int);
	~BATLayer();

	void render();

	std::vector<BATNode *> nodes;
};
