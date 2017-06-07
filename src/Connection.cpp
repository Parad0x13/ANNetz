#include "Connection.h"
#include "Utility.h"
#include "Neuron.h"
#include <string>

using namespace std;

Connection::Connection() {
	//
}

Connection::Connection(int start, Component *a, Component *b) : vectorStart(start), indexA(a), indexB(b) {
	//
}

void Connection::setInput() {
	indexB->setInput(vectorStart, indexA->output);
}

ostream& operator<<(ostream& stream, Connection& c) {
	stream << "Connection " << &c << ": ";

	// [TODO] Add error checking for NULL connections

	stream << c.indexA << " -> " << c.indexB << " offset: " << c.vectorStart;
	return stream;
};
