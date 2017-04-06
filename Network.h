#ifndef NETWORK_H
#define NETWORK_H

#include "headers.h"

class Network {
public:
	Neuron Neurons;
	double[] Input, Output;

	Network(int[]);
	virtual ~Network();

	double calc_Out(int[] * );
	
private:
	
};

#endif
