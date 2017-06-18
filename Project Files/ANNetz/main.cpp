#include <iostream>
#include <vector>
#include <Windows.h>

#include "Network.h"
#include "ComponentManager.h"
#include "DXFramework.h"
#include "Utility.h"

using namespace std;

int main(int argc, char *argv[]) {

	std::vector<::vector<double*>> inputs = std::vector<std::vector<double*>>(4);
	std::vector<::vector<double*>> outputs = std::vector<std::vector<double*>>(4);

	for (int i = 0;i < 4;i++) {
		inputs[i] = vector<double*>(2);
		outputs[i] = vector<double*>(1);
	}

	inputs[0][0]  = new double(0); inputs[0][1] = new double(0);
	inputs[1][0]  = new double(0); inputs[1][1] = new double(1);
	inputs[2][0]  = new double(1); inputs[2][1] = new double(0);
	inputs[3][0]  = new double(1); inputs[3][1] = new double(1);

	outputs[0][0] = new double(0);
	outputs[1][0] = new double(1);
	outputs[2][0] = new double(1);
	outputs[3][0] = new double(0);
	cout << exePath() << endl;
	Network network = Network({2, 2, 1});

	//cout << exePath() << endl;
	cout << network << endl;

	network.trainOn(inputs, outputs, 1000);

	cout << "Finished" << endl;

	for (int i = 0;i < 4;i++) {
		network.setInput(0, inputs[i]);
		network.calcOut();
		cout << *inputs[i][0] << *inputs[i][1] << " ";
		cout << *network.output[0] << endl;
	}
	
	cout << "initalize CNN" << endl;
	ComponentManager cm = ComponentManager(2, 1, 3);	// insize, outsize, length
	cm.setComponent(&network, 1, 0);

	cout << "Finished" << endl;

	for (int i = 0; i < 4; i++) {
		cout << *inputs[i][0] << *inputs[i][1] << " ";
		cout << *cm.calcOut(inputs[i])[0] << endl;
	}

	// [TODO] We need to find a better way of doing this...
	// [TODO][WARN] This no longer works after the project refactoring... need to get it working some other way
	/*TCHAR buffer[MAX_PATH];
	int bytes = GetModuleFileName(NULL, buffer, MAX_PATH);
	basic_string<TCHAR> currentDirectory(buffer);
	currentDirectory += "\\..\\..\\..\\ANN_data";
	cm.getDataSet(currentDirectory);*/

	DXFramework* framework = new DXFramework();
	framework->wWinMain();
	delete framework;
}
