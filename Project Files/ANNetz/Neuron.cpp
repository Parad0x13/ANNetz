#include <sstream>
#include "Neuron.h"
#include "Network.h"
#include "Utility.h"

using namespace std;

Neuron::Neuron(Network* _network, int _layer, int _index) : network(_network), layer(_layer), index(_index) {
	if (layer == 0) {
		weights = vector<double>(network->layers[_layer - 0].size()); 
		previousWeightDelta = vector<double>(network->layers[_layer - 0].size());
	}
	else {
		weights = vector<double>(network->layers[_layer - 1].size()); 
		previousWeightDelta = weights = vector<double>(network->layers[_layer - 1].size());
	}

	setRandomWeights();
}

Neuron::~Neuron() {
	// Neural connections will be managed on the stack (possibly), they will need to be managed here
}

// [TODO] Improve this algorithm using memoization
// [TODO] Don't only use Step TransferFunction
// [TODO] Implement request to network and iteration of network's reported connections
double Neuron::inputSum() {
	if (layer == 0) throw new exception("Inputlayer have no Inputsum");

	double retVal = bias;
	for (int i = 0; i < network->layers[layer - 1].size(); i++) {
		retVal += network->layers[layer - 1][i]->lastOutput * weights[i];
	}
	return retVal;
}

// [TODO] Improve this algorithm using memoization
double Neuron::output() {
	lastOutput = 1 / (1 + exp(-inputSum()));
	return lastOutput;
}

double Neuron::setOutput(double value) {
	lastOutput = value;
	return lastOutput;
}

void Neuron::setRandomWeights() {
	int count = weights.size();

	for (int i = 0; i < count; i++) {
		weights[i] = normalDistribution();
	}

	bias = normalDistribution();
	previousBiasDelta = 0;
}

void Neuron::adjustWeights(double lernRate, double momentum) {
	double bufferDelta;

	for (int j = 0; j < weights.size(); j++) {
		bufferDelta = error * network->layers[layer - 1][j]->lastOutput * lernRate +momentum * previousWeightDelta[j];
		weights[j] += bufferDelta;
		previousWeightDelta[j] = bufferDelta;
	}

	bufferDelta = error * lernRate + momentum * previousBiasDelta;
	bias += bufferDelta;
	previousBiasDelta = bufferDelta;
}

void Neuron::changeARandomWeight() {
	int rnd = getRandomInt(0, weights.size() - 1);
	weights[rnd] = normalDistribution();
}

void Neuron::calcError(double absolutError) {
	error = lastOutput * (1 - lastOutput) * absolutError;
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
