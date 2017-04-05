#include "headers.h"

// It's important to seed our random generator w/ system clock. Perfectly uniform distribution is achieved here.
default_random_engine random_engine(chrono::system_clock::now().time_since_epoch().count());

// [TODO] Fix the fact that std::string::length() cannot handle unicode
string generateTag(int len, string available) {
	uniform_int_distribution<int> distribution(0, available.length() - 1);
	string retVal = "";

	for(auto x = 0;x < len;x++)
		retVal += available[distribution(random_engine)];

	return retVal;
}
