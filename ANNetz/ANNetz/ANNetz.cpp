// ANNetz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Network.h"
using namespace std;

int main()
{
	Network network = Network({ 3, 2, 1 });

	cout << "This will be difficult to read via text..." << endl;
	cout << network << endl;
}

