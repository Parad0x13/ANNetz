#ifndef ComponentManager_H
#define ComponentManager_H

#include <vector>
#include "Utility.h"
#include "Component.h"
#include "Connection.h"

#include "PassThrough.h"
#include "Pooling.h"
#include "Filter.h"
#include "Network.h"

class ComponentManager {
public:
	ComponentManager(int, int, int);
	~ComponentManager();

	std::vector<double*> calcOut(std::vector<double*>);
	void setComponent(Component*, int, int);
private:
	int inputSize, OutputSize;

	std::vector<std::vector<Component*>> components;
	std::vector<std::vector<Connection*>> connections;
};

#endif
