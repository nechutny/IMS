#include "gateInput.h"
#include <stdio.h>
void GateInput::tick()
{
	setResult(1);
}

GateInput::GateInput(FILE* outFile)
{
	output = NULL;
	this->outFile = outFile;
	result = 0;
	delay = 0;
}
