#include <iostream>
#include <string>
#include "Network.h"
#include "Neuron.h"
#include "Connection.h"
#include "Component.h"

using namespace std;

Network::Network() {
	//
}

// In this network approach we fully interconnect Neurons in a layer by layer approach
Network::Network(vector<int> neuronsPerLayer) {
	int layerCount = neuronsPerLayer.size();
	layers = vector<vector<Neuron*>>(layerCount);

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

void Network::calcOut() {
//	vector<double> retVal;
//
//	// [TODO] Set inpput into the first layer
//	for (int i = 0; i < Layers.size(); i++) {
//		for (int j = 0; j < Layers[i].size(); j++) {
//			if (i == Layers.size() - 1) {
//				retVal.push_back(Layers[i][j]->output());
//			}
//		}
//	}
}

ostream& operator<<(ostream& stream, Network& n) {
	stream << "Network " << &n << " " << n.getInfo() << endl;
	return stream;
};
