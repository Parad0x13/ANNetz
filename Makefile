CC = g++
CFLAGS = -std=c++14 -static-libgcc -static-libstdc++
SOURCES = main.cpp Neuron.cpp Utility.cpp

all:
	$(CC) $(CFLAGS) $(SOURCES) -o ANNetz