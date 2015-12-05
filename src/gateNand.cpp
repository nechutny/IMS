#include "gateNand.h"
#include <stdio.h>
void GateNand::tick()
{
	char res = 1;
	for (unsigned i = 0; i < input.size(); i++)
	{
		res &= input[ i ]->getValue(delay);
	}

	setResult(!res);
}

GateNand::GateNand(FILE* outFile)
{
	output = NULL;
	this->outFile = outFile;
	result = 0;
	delay = DELAY_NAND;
}
