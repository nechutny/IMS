#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

void readHeader(FILE* fd)
{
	char header[30];
	fscanf(fd, "\"%[^\"]\"", header);
	if(strcmp(header, "\"ExpressPCB Netlist\""))
		throw 2;
		
	
}

std::vector<char> readParts(FILE* fd)
{
	std::vector<char> result;

	return result;
}

std::vector<char> readWires(FILE* fd)
{
	std::vector<char> result;

	return result;
}

void connectThem(std::vector<char>* parts, std::vector<char>* wires)
{
	
}
