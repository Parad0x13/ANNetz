#include "Connection.h"
#include "Utility.h"

using namespace std;

Connection::Connection(Neuron* _a, Neuron* _b, double _weight) {
	a = _a;
	b = _b;
	weight = _weight;
}

void Connection::setRandomWeights()
{
	weight = normalDitributedDouble();
}

ostream& operator<<(ostream& stream, Connection& c) {
	stream << "Connection " << &c << ": ";

	// [TODO] Add error checking for NULL connections

	stream << c.a << " -> " << c.b << " = " << c.weight;

	return stream;
};

