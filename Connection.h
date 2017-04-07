#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

class Neuron;

class Connection {
public:
	// [TODO] In the future allow connection to connect Networks as well as Neurons
	Connection(Neuron*, Neuron*, double = 0);

private:
	friend std::ostream& operator<<(std::ostream&, Connection&);

	Neuron* a;
	Neuron* b;
	double weight;
};

#endif
