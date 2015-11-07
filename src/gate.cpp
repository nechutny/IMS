#include "gate.h"
#include "wire.h"
#include "stdio.h"


Gate::Gate()
{
	output = NULL;
	result = 0;
	delay = 0;
}

Gate::~Gate()
{

}

void Gate::tick()
{
	fprintf(stderr,"Oh, you didn't!");
}

char Gate::getValue()
{
	return result;
}


unsigned long Gate::getDelay()
{
	return delay;
}

void Gate::connectWire(unsigned int pin, Wire* in)
{
	if(pin == 0)
	{
		output = in;
		in->notifyDelay(delay);
		in->addOutput(this);
	}
	else
	{
		input[ pin ] = in;
		in->addInput(this);
	}
}
