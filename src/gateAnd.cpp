#include "gateAnd.h"
#include "delays.h"
#include <stdio.h>

GateAnd::GateAnd(FILE* outFile)
{
	output = NULL;
	this->outFile = outFile;
	result = 0;
	delay = DELAY_AND;
}


void GateAnd::tick()
{
	char res = 1;
	for (unsigned i = 0; i < input.size(); i++)
	{
		res &= input[ i ]->getValue(delay);
	}

	setResult(res);
}

