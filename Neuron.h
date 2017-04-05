#ifndef NEURON_H
#define NEURON_H

#include "headers.h"

class Neuron {
public:
    Neuron();
    virtual ~Neuron();

    bool add_input(Neuron*);
    bool add_output(Neuron*);

	string tag = generateTag(3);
	string descriptor();

private:
	friend ostream& operator<<(ostream&, Neuron&);

	vector<Neuron*> inputs, outputs;	// We want to add by pointer so that they are not copied on the stack
};

#endif
