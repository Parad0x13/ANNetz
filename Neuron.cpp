#include <sstream>
#include "Neuron.h"

using namespace std;

Neuron::Neuron(Network* _network) {
	network = _network;
}

Neuron::~Neuron() {
	// Neural connections will be managed on the stack (possibly), they will need to be managed here
}

// [TODO] Improve this algorithm using memoization
// [TODO] Don't only use Step TransferFunction
// [TODO] Implement request to network and iteration of network's reported connections
double Neuron::inputSum() {
	double retVal;

	return retVal;
}

// [TODO] Improve this algorithm using memoization
double Neuron::output(TransferFunction tf) {
	double retVal = 0;

	switch (tf) {
	case Step:
		return 1;
		if (inputSum() > 0) {
			retVal = 1;
		}
		else {
			retVal = 0;
		}
		break;
	case Sigmoid:
		return 2;
		retVal = 1 / (1 + exp(-inputSum()));
		break;
	}

	return retVal;
}

string Neuron::descriptor() {
	stringstream ss;
	ss << "[" << tag << ": " << this << "]";
	return ss.str();
}

ostream& operator<<(ostream& stream, Neuron& n) {
	stream << n.descriptor();

	return stream;
};
