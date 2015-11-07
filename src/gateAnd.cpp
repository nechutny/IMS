#include "gateAnd.h"

void GateAnd::tick()
{
	char result = 0;
	for (unsigned i = 0; i < input.size(); i++) {
		result &= input[ i ]->getValue(delay);
	}
}