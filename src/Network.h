#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>
#include "Component.h"

class Neuron;
class Connection;

class Network : public Component{
public:
	Network();					// Default blank network
	Network(std::vector<int>);	// Standard layer by layer network
	~Network();

private:
	friend std::ostream& operator<<(std::ostream&, Network&);

public:
	// [TODO] In the future we should allow more complicated networks other than layer by layer
	//			Possibly get rid of vector<vector<Neuron*>> in favor of connections only?
	//			Maybe we could abstract vector<vector<Neuron*>> into a Structure class instead...
	std::string GetInfo();
	
	std::vector<std::vector<Neuron*>> Layers;
};

#endif
