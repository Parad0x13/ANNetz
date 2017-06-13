#ifndef PASSTHROUGH_H
#define PASSTHROUGH_H

#include <vector>
#include "Utility.h"

#include "Component.h"

class Passthrough : public Component{
public:
	Passthrough();
	Passthrough(int);
	~Passthrough();

	void calcOut();
};

#endif
