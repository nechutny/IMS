#include "wire.h"

Wire::Wire()
{
	maxDelay = 0;
}

Wire::~Wire()
{

}


void Wire::tack()
{
	char res = 0;
	for(unsigned i = 0; i < output.size(); i++)
	{
		res |= output[ i ]->getValue();
	}

	//printf("Wire output: %d\n", res);

	buffer.setValue(res);
}

char Wire::getValue(int delay)
{
	return buffer.getValue(delay);
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
