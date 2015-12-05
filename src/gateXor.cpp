#include "gateXor.h"
#include <stdio.h>
void GateXor::tick()
{
	setResult(input[ 0 ]->getValue(delay) != input[ 1 ]->getValue(delay));
}

GateXor::GateXor(FILE* outFile)
{
	output = NULL;
	this->outFile = outFile;
	result = 0;
	delay = DELAY_XOR;
}
