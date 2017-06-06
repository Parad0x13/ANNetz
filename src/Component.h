#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
class Component {
public:
	Component() {};
	int inputSize, outputSize;
	std::vector<double*> output;

	void setInput(int, std::vector<double*>);
	virtual void calcOut() = 0; // Implied  ]0, 1]
protected:
	std::vector<double*> input;
};

#endif