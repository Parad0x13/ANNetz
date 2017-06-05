#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
class Component {
public:
	Component() {};
	//int InputSize, OutputSize; TODO!
	std::vector<double> output;
	virtual void calcOut(std::vector<double>) = 0;		// Implied  ]0, 1[
};

#endif