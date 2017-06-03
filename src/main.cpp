#include <iostream>
#include "Network.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	std::vector<::vector<double>> inputs = std::vector<std::vector<double>>(4);
	std::vector<::vector<double>> outputs = std::vector<std::vector<double>>(4);

	for (int i = 0;i < 4;i++) {
		inputs[i] = vector<double>(2);
		outputs[i] = vector<double>(1);
	}

	inputs[0][0] = 0; inputs[0][1] = 0;
	inputs[1][0] = 0; inputs[1][1] = 1;
	inputs[2][0] = 1; inputs[2][1] = 0;
	inputs[3][0] = 1; inputs[3][1] = 1;
	outputs[0][0] = 0;
	outputs[1][0] = 1;
	outputs[2][0] = 1;
	outputs[3][0] = 0;

	Network network = Network({2, 2, 1});

	cout << "This will be difficult to read via text..." << endl;
	cout << network << endl;

	network.trainOn(inputs, outputs, 100000);

	cout << "Finished" << endl;
	for (int i = 0;i < 4;i++) {
		network.calcOut(inputs[i]);
		cout << inputs[i][0] << inputs[i][1] << " ";
		cout << network.output[0] << endl;
	}
}
