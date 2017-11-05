#ifndef UTILITY_H
#define UTILITY_H

#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

extern std::default_random_engine random_engine;	// Nicely available for use throughout project

std::string generateRandomTag(int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string generateTag(int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string getTag(int, int, std::string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

double normalDistribution();
int getRandomInt(int, int);
double getRandomDouble(double, double);
std::vector<std::string> splitString(std::string, char);
std::string getHex(char);

void error(std::string);
std::string exePath();

std::vector<std::string> getAllFiles(std::string);

std::vector<std::vector<std::string>> dataFromCSV(std::string);
#endif
