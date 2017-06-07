#ifndef ComponentManager_H
#define ComponentManager_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Utility.h"
#include "Component.h"
#include "Connection.h"

#include "PassThrough.h"
#include "Pooling.h"
#include "Filter.h"
#include "Network.h"

#include "EasyBMP.h"

class ComponentManager {
public:
	ComponentManager(int, int, int);
	~ComponentManager();

	std::vector<double*> calcOut(std::vector<double*>);
	void setComponent(Component*, int, int);
	void getDataSet(std::string);
private:
	int inputSize, OutputSize;

	std::vector<std::vector<double*>> targets;
	std::vector<std::vector<double*>> inputs;
	std::vector<double*> BMToArray(std::string path);

	std::vector<std::vector<Component*>> components;
	std::vector<std::vector<Connection*>> connections;
};

#endif
