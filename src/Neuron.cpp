#include <sstream>
#include "Neuron.h"
#include "Network.h"
#include "Utility.h"

using namespace std;

Neuron::Neuron(Network* _network, int _layer, int _index) {
	network = _network;
	layer = _layer;
	index = _index;

	if (layer == 0) { //no "syntactical sugar"
		weights = vector<double>(network->Layers[_layer].size());
	}
	else {
		weights = vector<double>(network->Layers[_layer - 1].size());
	}

	SetRandomWeights();
}

Neuron::~Neuron() {
	// Neural connections will be managed on the stack (possibly), they will need to be managed here
}

// [TODO] Improve this algorithm using memoization
// [TODO] Don't only use Step TransferFunction
// [TODO] Implement request to network and iteration of network's reported connections
double Neuron::inputSum() {
	double retVal = 0;
	return retVal;
}

// [TODO] Improve this algorithm using memoization
double Neuron::output() {
	double retVal = 0;

	retVal = 1 / (1 + exp(-inputSum()));

	return retVal;
}

void Neuron::SetRandomWeights()
{
	
	int count = weights.size();
	for (int i = 0; i < count; i++) {
		weights[i] = normalDistribution();
	}
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
