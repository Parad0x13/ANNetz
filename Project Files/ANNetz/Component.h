#pragma once

#include <vector>
#include "Utility.h"
class Component {
public:
	Component() {};
	int inputSize, outputSize;
	std::vector<double*> output;

	void setInput(int, std::vector<double*>);
	virtual void calcOut() = 0; // Implied  [0, 1]
	//DX stuff
	//virtual std::vector<SimpleVertex> getVertices() = 0;


protected:
	std::vector<double*> input;
};
