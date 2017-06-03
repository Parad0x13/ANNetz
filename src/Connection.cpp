#include "Connection.h"
#include "Utility.h"
#include "Neuron.h"
#include <string>

using namespace std;

Connection::Connection(Neuron* _a, Neuron* _b, double _weight) : a(_a), b(_b), weight(_weight) {
	//
}

void Connection::setRandomWeights() {
	weight = normalDistribution();
}

ostream& operator<<(ostream& stream, Connection& c) {
	stream << "Connection " << &c << ": ";

	// [TODO] Add error checking for NULL connections

	stream << c.a->tag << " -> " << c.b->tag << " = " << c.weight;

	return stream;
};
