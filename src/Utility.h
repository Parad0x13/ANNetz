#ifndef UTILITY_H
#define UTILITY_H

#include <random>

extern std::default_random_engine random_engine;	// Nicely available for use throughout project

std::string generateRandomTag(int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string generateTag(int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string getTag(int, int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

double normalDistribution();
int getRandomInt(int, int);

#endif
