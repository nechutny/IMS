#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

void readHeader(FILE* fd)
{
	char[30] header;
	fscanf("fd", "\"%[^\"]\"", header);
	if(strcmp(header, "\"ExpressPCB Netlist\""))
		throw 2;
		
	
}

std::vector readParts(FILE* fd)
{
	
}

std::vector readWires(FILE* fd)
{
	
}

void connectThem(std::vector* parts, std::vector* wires)
{
	
}
