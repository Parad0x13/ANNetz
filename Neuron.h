#ifndef NEURON_H
#define NEURON_H

#include "headers.h"

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
    virtual ~Neuron();

    bool addInput(Neuron*);
    bool addOutput(Neuron*);

	double inputSum();
	double output(TransferFunction);

	string tag = generateTag(3);
	string descriptor();

private:
	friend ostream& operator<<(ostream&, Neuron&);

	vector<Neuron*> inputs, outputs;	// We want to add by pointer so that they are not copied on the stack
};

#endif
