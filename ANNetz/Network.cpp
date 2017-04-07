#include <iostream>
#include "Network.h"
#include "Neuron.h"
#include "Connection.h"

using namespace std;

Network::Network() {
	//
}

// In this network approach we fully interconnect Neurons in a layer by layer approach
Network::Network(vector<int> neuronsPerLayer) {
	int layerCount = neuronsPerLayer.size();

	// Create all the Neurons in the network
	for (int d = 0;d < layerCount;d++) {
		vector<Neuron*> layer;
		int layerSize = neuronsPerLayer[d];

		for(int dd = 0;dd < layerSize;dd++) {
			Neuron *neuron = new Neuron(this);
			layer.push_back(neuron);
		}

		layers.push_back(layer);
	}

	// Interconect all Neurons to their next layer
	for (int d = 1;d < layerCount;d++) {
		int inputLayerSize = neuronsPerLayer[d - 1];
		int outputLayerSize = neuronsPerLayer[d];
		for (int inputIndex = 0;inputIndex < inputLayerSize;inputIndex++) {
			for (int outputIndex = 0;outputIndex < outputLayerSize;outputIndex++) {
				Neuron* input = layers[d - 1][inputIndex];
				Neuron* output = layers[d][outputIndex];
				Connection* connection = new Connection(input, output);
				addConnection(connection);
			}
		}
	}
}

Network::~Network() {
	//
}

void Network::addConnection(Connection* connection) {
	// [TODO] Do error checking here
	// [TODO] Update memoization stuff here
	connections.push_back(connection);
}

vector<Connection*> Network::getConnections(Neuron* neuron) {
	vector<Connection*> retVal;

	for (Connection* connection : connections) {
		//
	}

	return retVal;
}

ostream& operator<<(ostream& stream, Network& n) {
	stream << "Network " << &n << ":" << endl;

	for (auto connection : n.connections) {
		stream << "\t" << *connection << endl;
	}

	return stream;
};
