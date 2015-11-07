#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "read.h"

int main(int argc, char* argv[])
{
		FILE* fd = fopen("input.net", "r");
		
		readHeader(fd);
		std::vector<char> parts = readParts(fd);
		std::vector<char> wires = readParts(fd);
}
