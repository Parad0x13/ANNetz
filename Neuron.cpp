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

double Neuron::calc_Output(Neuron::TransferFunction* tf) {
	switch ((int)tf) {
	case (int)Neuron::Step:
		if (InputSum > 0) { Output = 1; }
		else { Output = 0; }
		break;
	case (int)Neuron::Sigmoid: Output = 1 / (1 + std::exp(-InputSum)); break;
	}
	return Output;
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
