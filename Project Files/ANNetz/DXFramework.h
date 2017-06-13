#pragma once

#include <windows.h>

#define WIN32_LEAN_AND_MEAN

class DXFramework {
public:
	DXFramework();
	~DXFramework();

	bool initialize();
	void begin();

private:
	bool createDXWindow(char* windowTitle, int x, int y, int width, int height);

	char* applicationName;
	HINSTANCE hInstance;
};
