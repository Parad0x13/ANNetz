#ifndef NEURON_H
#define NEURON_H

#include "Utility.h"

class Network;

class Neuron {
public:
	Neuron(Network*, int, int);
    ~Neuron();

	std::string tag = generateTag(3);
	std::string descriptor();
	Network* network = NULL;

	double output();
	double setOutput(double);
	
	double lastOutput;
	double error;
	std::vector<double> weights;

	void setRandomWeights();
	void adjustWeights(double, double);
	void calcError(double);
	void changeARandomWeight();

private:
	friend std::ostream& operator<<(std::ostream&, Neuron&);
	int layer, index;

	double inputSum();
		
	std::vector<double> previousWeightDelta;
	double bias, previousBiasDelta;
};

#endif
