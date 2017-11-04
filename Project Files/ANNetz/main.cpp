#include <iostream>
#include <vector>
#include <Windows.h>

#include "Network.h"
#include "ComponentManager.h"
#include "DXFramework.h"
#include "Utility.h"
#include "BATNet.h"

using namespace std;

// [NOTE] Ctrl+F5 runs build, run, system("PAUSE") automatically, will run previous success if build fails though so watch out

int main(int argc, char *argv[]) {
	// [TODO] We need to find a better way of doing this...
	// [TODO][WARN] This no longer works after the project refactoring... need to get it working some other way
	/*TCHAR buffer[MAX_PATH];
	int bytes = GetModuleFileName(NULL, buffer, MAX_PATH);
	basic_string<TCHAR> currentDirectory(buffer);
	currentDirectory += "\\..\\..\\..\\ANN_data";
	cm.getDataSet(currentDirectory);*/

	// [NOTE] Parad0x13 removed this code as the DX11 stuff wasn't workin (resources were not included)
	// [NOTE] Also to note the copying of files into the build folder should be done automatically e.g. https://gamedev.stackexchange.com/questions/46722/why-cant-my-exe-find-my-fx-file
	/*cout << exePath() << endl;
	DXFramework *framework = new DXFramework();
	framework->wWinMain();
	delete framework;*/

	BATNet *net = new BATNet();
	net->setDataToClassify("irisData.txt", 4, 5);
	net->addLayer(4);
	net->addLayer(6);
	net->addLayer(3);
	net->learn(1);
	net->render();
}
