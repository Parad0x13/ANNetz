#include "headers.h"

using namespace std;

int main() {
    Neuron neuron;
    Neuron neuron2;

    neuron.add_input(&neuron2);

    cout << neuron << endl;

    cout << &neuron << endl;
    cout << &neuron2 << endl;
}
