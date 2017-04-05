#include "headers.h"

Neuron::Neuron() {
	//
}

Neuron::~Neuron() {
	// Neural connections will be managed on the stack (possibly), they will need to be managed here
}

bool Neuron::add_input(Neuron* n) {
	inputs.push_back(n);

	return true;
}

bool Neuron::add_output(Neuron* n) {
	outputs.push_back(n);

	return true;
}

string Neuron::descriptor() {
	stringstream ss;
	ss << "[" << tag << ": " << this << "]";
	return ss.str();
}

ostream& operator<<(ostream& stream, Neuron& n) {
	stream << n.descriptor();

	stream << "\n\tInputs\n";
	for(ptr : n.inputs) {
		Neuron &input = *ptr;
		stream << "\t" << input.descriptor() << endl;
	}

	stream << "\tOutputs\n";
	for(ptr : n.outputs) {
		Neuron &output = *ptr;
		stream << "\t" << output.descriptor() << endl;
	}

	return stream;
};
