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

	//DX
	std::vector<SimpleVertex> getVertices();
	std::vector<short> getIndices();

private:
	int inX, inY;
	int outX, outY;
};
