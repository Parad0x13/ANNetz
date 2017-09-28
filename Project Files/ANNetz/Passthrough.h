#pragma once

#include <vector>
#include "Utility.h"

#include "Component.h"

class Passthrough : public Component{
public:
	Passthrough();
	Passthrough(int);
	~Passthrough();

	void calcOut();
	std::vector<SimpleVertex> getVertices();
	std::vector<short> getIndices();
};
