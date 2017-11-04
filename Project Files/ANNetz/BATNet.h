#pragma once
#include <string>
#include <vector>

#include "BATLayer.h"

class BATNet {
public:
	BATNet();
	~BATNet();

	void render();
	void setDataToClassify(std::string, int, int);		// Assumes all dataPoints preceed classIndex
	void addLayer(int);

	std::vector<BATLayer *> layers;
	std::vector<std::vector<double>> classifyData;		// [TODO] Make it so classifyData can be types other than double
};
