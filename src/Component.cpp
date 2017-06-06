#include "Component.h"

void Component::setInput(int startIndex, std::vector<double*> in) {
	for (int i = 0; i < in.size(); i++) {
		input[i] = in[startIndex + i];
	}
}
