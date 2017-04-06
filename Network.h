#ifndef NETWORK_H
#define NETWORK_H

#include "headers.h"

class Network {
public:	
	double[] input, output;

	Network(vector<int>);
	virtual ~Network();

	double calc_Out(int[] * );
	
private:
	vector<vector<Neuron>> neurons;
};

#endif
