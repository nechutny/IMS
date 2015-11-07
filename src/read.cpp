#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

void readHeader(FILE* fd)
{
	char* header=(char*)malloc(100);
	int a,i;
	
	if(fscanf(fd, "\"%[^\"]\"", header) != 1)
	{
		throw 2;
	}
	
	if(strcmp(header, "ExpressPCB Netlist"))
	{
		throw 2;
	}
	
	if(fscanf(fd, "\n\"%[^\"]\"", header) != 1)
	{
		throw 2;
	}
	
	if(fscanf(fd, "\n%d", &a) != 1)
	{
		throw 2;
	}
	
	if(a != 1)
	{
		throw 2;
	}
	
	if(fscanf(fd, "\n%d", &a) != 1)
	{
		throw 2;
	}
	
	if(fscanf(fd, "\n%d\n", &a) != 1)
	{
		throw 2;
	}
	
	if(a != 0)
	{
		throw 3;
	}
	
	for(i = 0; i < 3; i++)
	{
		if(fgets(header,10, fd) == NULL)
		{
			throw 2;
		}
		
		if(strcmp(header, "\"\"\n"))
		{
			throw 2;
		}
	}
	
}

std::vector<Gate*> readParts(FILE* fd)
{
	std::vector<Gate*> result;

	return result;
}

std::vector<Wire*> readWires(FILE* fd)
{
	std::vector<Wire*> result;

	return result;
}

void connectThem(std::vector<Gate*>* parts, std::vector<Wire*>* wires)
{
	
}
