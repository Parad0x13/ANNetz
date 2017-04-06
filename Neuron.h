#ifndef NEURON_H
#define NEURON_H

#include "headers.h"

class Neuron {
public:
	enum TransferFunction{Step, Sigmoid}; //step = if x > 0 then 1 else 0; sigmoid = 1 / (1 + e^-x)

    Neuron();
    virtual ~Neuron();

    bool add_input(Neuron*);
    bool add_output(Neuron*);

	double Output;
	double calc_Output(TransferFunction*);

	string tag = generateTag(3);
	string descriptor();

private:
	double InputSum;
	double[] Weights;

	friend ostream& operator<<(ostream&, Neuron&);

	vector<Neuron*> inputs, outputs;	// We want to add by pointer so that they are not copied on the stack
};

#endif
