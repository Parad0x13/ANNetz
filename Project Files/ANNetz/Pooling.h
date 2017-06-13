#pragma once

#include <vector>
#include <string>
#include "Component.h"

class Pooling : public Component {
public:
	void calcOut();
	void refreshInputSize(int, int);

	Pooling(int, int);
	~Pooling();

private:
	int inX, inY;
	int outX, outY;
};
