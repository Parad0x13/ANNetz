#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include "Component.h"

class Connection {
public:
	Connection();
	Connection(int, Component*, Component*);
	int vectorStart = 0;
	Component *indexA, *indexB;

	void setInput();

private:
	friend std::ostream& operator<<(std::ostream&, Connection&);
};

#endif
