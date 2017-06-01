#ifndef NEURON_H
#define NEURON_H

#include "Utility.h"

class Network;

class Neuron {
public:
	Neuron(Network*, int, int);
    ~Neuron();

	double output();
	void setRandomWeights();

	std::string tag = generateTag(3);
	std::string descriptor();
	Network* network = NULL;

private:
	friend std::ostream& operator<<(std::ostream&, Neuron&);
	int layer, index;

	double inputSum();
	std::vector<double> weights;
	double lastOutput;
};

#endif
