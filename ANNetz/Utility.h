#ifndef UTILITY_H
#define UTILITY_H

#include <random>

extern std::default_random_engine random_engine;	// Nicely available for use throughout project
std::string generateTag(int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

double normalDitributedDouble();
#endif
