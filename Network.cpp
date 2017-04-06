#include "headers.h"

Network::Network(vector<int> neuronsPerLayer) {
	Neurons = new neuronsPerLayer.size();
	for (auto i = 0; i < neuronsPerLayer.size(); i++) {
		Neurons[i] = new Neuron[neuronsPerLayer];
	}
}

Network::~Network() {

}

double Network::calc_Out(int[] npl) {
	npl 
}



