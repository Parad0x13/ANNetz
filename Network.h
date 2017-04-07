#ifndef NETWORK_H
#define NETWORK_H

#include <vector>

class Neuron;
class Connection;

class Network {
public:
	Network();					// Default blank network
	Network(std::vector<int>);	// Standard layer by layer network
	~Network();

private:
	friend std::ostream& operator<<(std::ostream&, Network&);

	void addConnection(Connection*);
	std::vector<Connection*> getConnections(Neuron*);
	//void removeConnection(Connection*);

public:
	// [TODO] In the future we should allow more complicated networks other than layer by layer
	//			Possibly get rid of vector<vector<Neuron*>> in favor of connections only?
	//			Maybe we could abstract vector<vector<Neuron*>> into a Structure class instead...
	std::vector<std::vector<Neuron*>> layers;
	std::vector<Connection*> connections;
};

#endif
