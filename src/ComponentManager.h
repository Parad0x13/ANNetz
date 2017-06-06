#ifndef ComponentManager_H
#define ComponentManager_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
//#include <bmp.h>

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
	void getDataSet(std::string);
private:
	int inputSize, OutputSize;

	
	std::vector<std::vector<double*>> targets;
	std::vector<std::vector<double*>> inputs;
	std::vector<double*> BmToArray(std::string path);

	std::vector<std::vector<Component*>> components;
	std::vector<std::vector<Connection*>> connections;
};

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct tagBITMAPFILEHEADER {
	WORD  bfType;
	DWORD bfSize;
	WORD  bfReserved1;
	WORD  bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;
	LONG  biWidth;
	LONG  biHeight;
	WORD  biPlanes;
	WORD  biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG  biXPelsPerMeter;
	LONG  biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#endif
