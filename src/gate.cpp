#include "gate.h"
#include "wire.h"
#include "stdio.h"


Gate::Gate()
{
	output = NULL;
	this->outFile = NULL;
	result = 0;
	delay = 0;
}

Gate::~Gate()
{

}

void Gate::setResult(char result)
{
	fprintf(outFile, ", %d", result ? 1 : 0);
	this->result = result;
}

void Gate::tick()
{
	fprintf(stderr,"Oh, you didn't!");
}

char Gate::getValue()
{
	//printf("Gate output: %d\n", result);
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
		std::vector<Wire*>::iterator it = input.end();
		input.insert(it, in);
		in->addInput(this);
	}
}
