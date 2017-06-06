#ifndef PassThrough_H
#define PassThrough_H

#include <vector>
#include "Utility.h"
#include "Component.h"

class PassThrough : public Component{
public:
	PassThrough();
	PassThrough(int);
	~PassThrough();

	void calcOut();
private:

};

#endif

