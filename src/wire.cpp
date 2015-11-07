#include "wire.h"

Wire::Wire()
{
	input.begin();
	output.begin();
}

Wire::~Wire()
{
}


void Wire::tack()
{

}

char Wire::getValue(int delay)
{
	return 0;
}


void Wire::notifyDelay(unsigned long delay)
{
	if(maxDelay < delay)
	{
		maxDelay = delay;
		buffer.increaseSize(maxDelay);
	}
}

void Wire::addInput(Gate *in)
{
	std::vector<Gate*>::iterator it = input.end();
	input.insert(it, in);
}

void Wire::addOutput(Gate *in)
{
	std::vector<Gate*>::iterator it = output.end();
	output.insert(it, in);
}