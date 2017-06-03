#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
class Component {
public:
	Component() {};
	std::vector<double> output;
	//always put in values between 0 and 1;
	virtual void calcOut(std::vector<double>) = 0;
};

#endif