#include "headers.h"

using namespace std;

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

/*bool Neuron::add_output(Neuron& n) {
	outputs.push_back(n);

	return true;
}*/

ostream& operator<<(ostream& stream, Neuron& n) {
	stream << "Neuron(" << &n << ") [" << n.tag << "]";

	stream << "\n\tInputs: ";
	for(input : n.inputs)
		stream << (*input).tag << ": " << input;

	/*stream << "\n\tOutputs: ";
	for(output : n.outputs)
		stream << output.tag;*/

	return stream;
};
