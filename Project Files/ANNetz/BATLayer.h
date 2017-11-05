#pragma once
#include <vector>
#include <string>

#include "BATNode.h"

class BATLayer {
public:
	BATLayer(int);
	~BATLayer();

	void render(std::string = "    [BATLayer]");
	void setPreviousLayer(BATLayer *layer);

	std::vector<BATNode *> nodes;
};
