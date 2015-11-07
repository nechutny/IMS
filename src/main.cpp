#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "read.h"
#include "gate.h"
#include "wire.h"

int main(int argc, char* argv[])
{
		FILE* fd = fopen("input.net", "r");
		
		readHeader(fd);
		std::vector<Gate*> parts = readParts(fd);
		std::vector<Wire*> wires = readWires(fd);
}
