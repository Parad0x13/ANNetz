#include <chrono>
#include "Utility.h"

using namespace std;

// It's important to seed our random generator w/ system clock. Perfectly uniform distribution is achieved here.
default_random_engine random_engine(chrono::system_clock::now().time_since_epoch().count());

// [TODO] Fix the fact that std::string::length() cannot handle unicode
string generateRandomTag(int len, string available) {
	uniform_int_distribution<int> distribution(0, available.length() - 1);
	string retVal = "";

	for(auto x = 0;x < len;x++)
		retVal += available[distribution(random_engine)];

	return retVal;
}

int currentTagIndex;
std::string generateTag(int len, string available)
{
	return GetTag(currentTagIndex, len);
	currentTagIndex++;
}

std::string GetTag(int index, int len, string available)
{
	string ret = "";
	int buffer = 0;
	int basis;
	if (index >= pow(available.length(), len)) {
		return "Overflow";
	}
	for (int i = len - 1; i > -1; i--) {
		basis = pow(available.length(), i);
		buffer = index / basis;
		index -= buffer * basis;
		ret += available[buffer];
	}

	return ret;
}

double normalDistribution() {
	uniform_real_distribution<double> distribution(0, 1);
	double u1 = distribution(random_engine);
	double u2 = distribution(random_engine);

	return sqrt(-2 * log(u1)) * cos(2 * 3.141592 * u2);
}