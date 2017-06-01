#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
class Component {
public:
	Component() {};
	std::vector<double> output;
	std::vector<double*> input;
	virtual void calcOut() = 0;
};

#endif