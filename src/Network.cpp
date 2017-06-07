#include <iostream>
#include <string>
#include <vector>
#include "Network.h"
#include "Neuron.h"
#include "Connection.h"
#include "Component.h"
#include "Utility.h"

using namespace std;

Network::Network() {
	//
}

// In this network approach we fully interconnect Neurons in a layer by layer approach
Network::Network(vector<int> neuronsPerLayer) {
	int layerCount = neuronsPerLayer.size();
	inputSize = neuronsPerLayer[0];
	outputSize = neuronsPerLayer[layerCount - 1];
	output = vector<double*>(outputSize);
	input = vector<double*>(inputSize);

	layers = vector<vector<Neuron*>>(layerCount);
	lastError = vector<double>(outputSize);
	// Create all the Neurons in the network
	for (int d = 0;d < layerCount;d++) {
		int layerSize = neuronsPerLayer[d];
		layers[d] = vector<Neuron*>(layerSize);
		
		for (int dd = 0;dd < layerSize;dd++) {
			Neuron *neuron = new Neuron(this, d, dd);
			layers[d][dd] = neuron;
		}
	}

	// [TODO] Find out why this comment is on it's very own line without any logic following it
	// Interconect all Neurons to their next layer
}

Network::~Network() {
	//
}

std::string Network::getInfo() {
	string s = "Layers: ";
	for (int i = 0;i < layers.size();i++) {
		s.append(std::to_string(layers[i].size()) + " ");
	}
	return s;
}

double Network::AbsoluteError(std::vector<std::vector<double*>> inputs, std::vector<std::vector<double*>> targets) {
	double retVal = 0;

	for (int i = 0;i < inputs.size();i++) {
		input = inputs[i];
		backpropagate(targets[i], 0, 0);
		for (int j = 0;j < outputSize;j++) {
			retVal += abs(layers[layers.size() - 1][j]->error);
		}
	}
	
	return retVal;
}

// Carefull! the normal inputs gets overwritten here because you give the network an inputset
void Network::backpropagate(std::vector<double*> target, double learnRate, double momentum) {
	if (target.size() != outputSize) throw new exception("Invalid target length");

	calcOut();

	// Set errors in output layer 
	for (int j = 0;j < outputSize;j++) {
		lastError[j] = *target[j] - *output[j];
		layers[layers.size() - 1][j]->calcError(lastError[j]);
		layers[layers.size() - 1][j]->adjustWeights(learnRate, momentum);
	}

	if (learnRate != 0) {
		for (int i = layers.size() - 2;i > 0;i--) {
			for (int j = 0;j < layers[i].size();j++) {
				double bError = 0;
				for (int k = 0;k < layers[i + 1].size();k++) {
					bError += layers[i + 1][k]->error * layers[i + 1][k]->weights[j];	// Maybe durschnitt
				}

				layers[i][j]->calcError(bError);
				layers[i][j]->adjustWeights(learnRate, momentum);
			}
		}
	}
}

void Network::calcOut() {
	if (input.size() != inputSize) throw new exception("Invalid Input length");

	for (int j = 0;j < inputSize;j++) {
		layers[0][j]->setOutput(*input[j]);
	}

	for (int i = 1; i < layers.size(); i++) {
		for (int j = 0;j < layers[i].size();j++) {
			layers[i][j]->output();
		}
	}

	if(output.size() != outputSize) throw new exception("Invalid Output length");

	for (int i = 0; i < output.size(); i++) {
		output[i] = new double(layers[layers.size() - 1][i]->lastOutput);
	}
}

double Network::trainOn(std::vector<std::vector<double*>> inputs, std::vector<std::vector<double*>> targets, int iterations) {
	// [TODO] Do some cuda stuff over here
	int rnd;
	double lernrate = 1 / (double)inputSize;
	double bufferError = 0;
	double currentError = 0;
	double deviation = 0;
	//[todo] give an maximum allowed error with the TrainOn call to decide whether this local minima is good or bad
	for (int i = 0; i < iterations; i++) {
		rnd = getRandomInt(0, inputs.size() - 1);

		input = inputs[rnd];
		backpropagate(targets[rnd], lernrate / (i / 1000 + 1), 0.1);
		if (i % 100 == 0) {
			currentError = AbsoluteError(inputs, targets);
			deviation = fmax(bufferError, currentError) - fmin(bufferError, currentError);

			if (bufferError == 0) bufferError = currentError;
			cout << "Itaration: " << i << "  \tAbsolut Error = " << currentError << "  \tDeviation: " << deviation << endl;

			if (i % 10000 == 0) {
				// Random change
				if (deviation <= 0.0001) {
					rnd = getRandomInt(1, layers.size() - 1);
					layers[rnd][getRandomInt(0, layers[rnd].size() - 1)]->changeARandomWeight();
					cout << "Did random weight change" << endl;
				}
			}
			else {
				// Jump
				if (i % 1000 == 0) {
					if (deviation <= 0.002) {
						rnd = getRandomInt(0, inputs.size() - 1);
						cout << "Did Jump" << endl;
						input = inputs[rnd];
						backpropagate(targets[rnd], 2, 0);
						i++;
					}
				}
			}
		}

		bufferError = currentError;
	}

	return AbsoluteError(inputs, targets);
}

ostream& operator<<(ostream& stream, Network& n) {
	stream << "Network " << &n << " " << n.getInfo() << endl;
	return stream;
};
