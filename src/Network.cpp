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
	output = vector<double>(outputSize);

	layers = vector<vector<Neuron*>>(layerCount);
	lastError = vector<double>(outputSize);
	// Create all the Neurons in the network
	for (int d = 0; d < layerCount; d++) {
		int layerSize = neuronsPerLayer[d];
		layers[d] = vector<Neuron*>(layerSize);
		
		for (int dd = 0; dd < layerSize; dd++) {
			Neuron *neuron = new Neuron(this, d, dd);
			layers[d][dd] = neuron;
		}
	}

	// Interconect all Neurons to their next layer
}

Network::~Network() {
	//
}

std::string Network::getInfo() {
	string s = "Layers: ";
	for (int i = 0; i < layers.size(); i++) {
		s.append(std::to_string(layers[i].size()) + " ");
	}
	return s;
}

double Network::AbsoluteError(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> targets)
{
	double retVal = 0;

	for (int i = 0; i < inputs.size(); i++) {
		backpropagate(inputs[i], targets[i], 0, 0);
		for (int j = 0; j < outputSize; j++) {
			retVal += abs(layers[layers.size() - 1][j]->error);
		}
	}
	
	return retVal;
}

void Network::backpropagate(std::vector<double> _input, std::vector<double> target, double lernRate, double momentum)
{
	if (_input.size() != inputSize) throw new exception("Invalid input length");
	if (target.size() != outputSize) throw new exception("Invalid target length");

	calcOut(_input);

	//set errors in output layer 
	for (int j = 0; j < outputSize; j++) {
		lastError[j] = target[j] - output[j];
		layers[layers.size() - 1][j]->calcError(lastError[j]);
		layers[layers.size() - 1][j]->adjustWeights(lernRate, momentum);
	}
	if (lernRate != 0) {
		for (int i = layers.size() - 2; i > 0; i--)
		{
			for (int j = 0; j < layers[i].size(); j++)
			{
				double bError = 0;
				for (int k = 0; k < layers[i + 1].size(); k++)
				{
					bError += layers[i + 1][k]->error * layers[i + 1][k]->weights[j];//maybe durschnitt
				}

				layers[i][j]->calcError(bError);
				layers[i][j]->adjustWeights(lernRate, momentum);
			}
		}
	}

}
void Network::calcOut(std::vector<double> input) {
	if (input.size() != inputSize) throw new exception("Invalid Input length");

	for (int j = 0; j < inputSize; j++) {
		layers[0][j]->setOutput(input[j]);
	}
	for (int i = 1; i < layers.size(); i++) {
		for (int j = 0; j < layers[i].size(); j++) {
			layers[i][j]->output();
		}
	}

	if(output.size() != outputSize) throw new exception("invalid Output length");
	for (int i = 0; i < output.size(); i++) {
		output[i] = layers[layers.size() - 1][i]->lastOutput;
	}
}

double Network::trainOn(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> targets,  int iterations)
{
	// [TODO] Do some cuda stuff over here
	int rnd;
	for (int i = 0; i < iterations; i++) {
		rnd = getRandomInt(0, inputs.size() - 1);

		backpropagate(inputs[rnd], targets[rnd], 0.2, 0.1);
		if (i % 100 == 0) cout << "Itaration " << i << "\t Absolut Error = " << AbsoluteError(inputs, targets) << endl;
	}

	return AbsoluteError(inputs, targets);
}

ostream& operator<<(ostream& stream, Network& n) {
	stream << "Network " << &n << " " << n.getInfo() << endl;
	return stream;
};