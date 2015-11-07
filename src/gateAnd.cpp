#include "gateAnd.h"
#include <stdio.h>
void GateAnd::tick()
{
	char res = 0;
	for (unsigned i = 0; i < input.size(); i++)
	{
		res &= input[ i ]->getValue(delay);
	}

	result = res;
}