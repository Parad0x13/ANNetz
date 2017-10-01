#include <iostream>
#include <vector>
#include <Windows.h>

#include "Network.h"
#include "ComponentManager.h"
#include "DXFramework.h"
#include "Utility.h"

using namespace std;

int main(int argc, char *argv[]) {
	// [TODO] We need to find a better way of doing this...
	// [TODO][WARN] This no longer works after the project refactoring... need to get it working some other way
	/*TCHAR buffer[MAX_PATH];
	int bytes = GetModuleFileName(NULL, buffer, MAX_PATH);
	basic_string<TCHAR> currentDirectory(buffer);
	currentDirectory += "\\..\\..\\..\\ANN_data";
	cm.getDataSet(currentDirectory);*/

	cout << exePath() << endl;
	DXFramework* framework = new DXFramework();
	framework->wWinMain();

	delete framework;
}
