#ifndef NEURON_H
#define NEURON_H

#include "Utility.h"

class Network;

class Neuron {
public:
	/*	Step:
			1, if x > 0
			0, otherwise
		Sigmoid:
			1 / (1 + e^-x)	*/
	// [TODO] Decide if we want TransferFunctions to belong to Neuron, or to a dedicated ANN math library
	enum TransferFunction{Step, Sigmoid};

    Neuron();
    ~Neuron();

	double inputSum();
	double output(TransferFunction);

	std::string tag = generateTag(3);
	std::string descriptor();

	Network *network = NULL;

private:
	friend std::ostream& operator<<(std::ostream&, Neuron&);
};

#endif
