#include <iostream>
#include "Network.h"

using namespace std;

int main() {
	Network network = Network({ 3, 2, 1 });

	cout << "This will be difficult to read via text..." << endl;
	cout << network << endl;

	int age;
	cout << "Put in a Number pls ";
		cin >> age;
		cout << "you just typed " << age << "\ntype another number to exit ";
		cin >> age;
		cout << "See you later Alligator";
}