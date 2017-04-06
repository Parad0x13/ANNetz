#include "headers.h"

Neuron::Neuron() {
	//
}

Neuron::~Neuron() {
	// Neural connections will be managed on the stack (possibly), they will need to be managed here
}

bool Neuron::addInput(Neuron* n) {
	inputs.push_back(n);
	
	return true;
}

bool Neuron::addOutput(Neuron* n) {
	outputs.push_back(n);

	return true;
}

// [TODO] Improve this algorithm using memoization
// [TODO] Don't only use Step TransferFunction
double Neuron::inputSum() {
	double retVal = 0;

	for (auto ptr : inputs) {
		Neuron &input = *ptr;
		retVal += input.output(Step);
	}

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

	stream << "\n\tInputs\n";
	for(auto ptr : n.inputs) {
		Neuron &input = *ptr;
		stream << "\t" << input.descriptor() << endl;
	}

	stream << "\tOutputs\n";
	for(auto ptr : n.outputs) {
		Neuron &output = *ptr;
		stream << "\t" << output.descriptor() << endl;
	}

	return stream;
};
