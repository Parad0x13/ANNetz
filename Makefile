CC = g++
CFLAGS = -std=c++14 -static-libgcc -static-libstdc++
SOURCES = main.cpp Neuron.cpp Utility.cpp Network.cpp Connection.cpp

all:
	$(CC) $(CFLAGS) $(SOURCES) -o ANNetz