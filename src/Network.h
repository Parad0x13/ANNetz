#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>

#include "Component.h"

class Neuron;
class Connection;

class Network : public Component {
public:
	Network();					// Default blank network
	Network(std::vector<int>);	// Standard layer by layer network
	~Network();

	void calcOut();
	double trainOn(std::vector<std::vector<double*>>, std::vector<std::vector<double*>>, int);
	// [TODO] In the future we should allow more complicated networks other than layer by layer
	//			Possibly get rid of vector<vector<Neuron*>> in favor of connections only?
	//			Maybe we could abstract vector<vector<Neuron*>> into a Structure class instead...
	std::string getInfo();
	std::vector<std::vector<Neuron*>> layers;
private:
	double AbsoluteError(std::vector<std::vector<double*>>, std::vector<std::vector<double*>>);	
	void backpropagate(std::vector<double*>, double, double);
	std::vector<double> lastError;

	friend std::ostream& operator<<(std::ostream&, Network&);
};

#endif
