#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#include "read.h"

#include "wire.h"
#include "gate.h"

#include "gateAnd.h"
#include "gateOr.h"
#include "gateNot.h"
#include "gateNand.h"
#include "gateXor.h"
#include "gateInput.h"


gateType hashGate(char* type)
{
	if(strcmp(type, "AND") == 0)
	{
		return AND;
	}
	
	if(strcmp(type, "OR") == 0)
	{
		return OR;
	}
	
	if(strcmp(type, "NAND") == 0)
	{
		return NAND;
	}
	
	if(strcmp(type, "XOR") == 0)
	{
		return XOR;
	}
	
	if(strcmp(type, "NOT") == 0)
	{
		return NOT;
	}
	
	if(strcmp(type, "INPUT") == 0)
	{
		return INPUT;
	}
	
	throw 2;
}

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
	
	free(header);
	
}

std::vector<Gate*> readParts(FILE* fd)
{
	std::vector<Gate*> result;
	
	char* header=(char*)malloc(100);
	char* identificator=(char*)malloc(100);
	char* label=(char*)malloc(100);
	char pom;
	Gate *gateTmp;
	std::vector<Gate*>::iterator it = result.end();

	
	if(fscanf(fd, "\n\"%[^\"]\"", header) != 1)
	{
		throw 2;
	}
	
	if(strcmp(header, "Part IDs Table"))
	{
		throw 2;
	}
	
	while(1)
	{
		if(fgetc(fd) == EOF)
		{
			throw 2;
		}
		
		pom = fgetc(fd);
		
		if(pom == '\n')
		{
			break;
		}
		
		if( fscanf(fd, "%[^\"]\" \"%[^\"]\" \"\"",identificator, label) != 2)
		{
			throw 2;
		}
		
		it = result.end();
		switch(hashGate(label))
		{
			case AND:
				gateTmp = (Gate*)new GateAnd;
			break;

			case OR:
				gateTmp = (Gate*)new GateOr;
			break;
				
			case NAND:
				gateTmp = (Gate*)new GateNand;
			break;
				
			case XOR:
				gateTmp = (Gate*)new GateXor;
			break;
				
			case NOT:
				gateTmp = (Gate*)new GateNot;	
				
			case INPUT:
				gateTmp = (Gate*)new GateInput;	
			break;			
		}
		result.insert(it, gateTmp);
		//printf("\n%s,   %s\n", identificator, label);
	}	
	
	free(header);
	free(label);
	free(identificator);

	return result;
}

std::vector<Wire*> readWires(FILE* fd)
{
	std::vector<Wire*> result;
	
	char* header=(char*)malloc(100);
	char* identificator=(char*)malloc(100);
	char pom;
	int a;

	std::vector<Wire*>::iterator is = result.end();
	Wire *wireTmp;
	
	if(fscanf(fd, "\n\"%[^\"]\"", header) != 1)
	{
		throw 2;
	}
	
	if(strcmp(header, "Net Names Table"))
	{
		throw 2;
	}
	
	while(1)
	{
		if(fgetc(fd) == EOF)
		{
			throw 2;
		}
		
		pom = fgetc(fd);
		
		if(pom == '\n')
		{
			break;
		}
		
		if( fscanf(fd, "%[^\"]\" %d",identificator, &a) != 2)
		{
			throw 2;
		}
		//printf("\n%s,   %d\n", identificator, a);
		
		wireTmp = new Wire;
		is = result.end();
		result.insert(is, wireTmp);
	}	

	return result;
}

void connectThem(FILE* fd, std::vector<Gate*>* parts, std::vector<Wire*>* wires)
{
	int wiresL, partL, pin, conectionsL;
	char* header=(char*)malloc(100);
	if(fscanf(fd, "\n\"%[^\"]\"", header) != 1)
	{
		throw 2;
	}
	
	if(strcmp(header, "Net Connections Table"))
	{
		throw 2;
	}
	
	while(fscanf(fd,"%d %d %d %d", &wiresL, &partL, &pin, &conectionsL) == 4)
	{
		printf("%d %d\n", partL, wiresL);
		((*parts)[partL-1])->connectWire(pin, (*wires)[wiresL-1]);
		//proc to nefunguje?
	}
	
	free(header);
	//nacis prvni tri cisla, propojit, hotovo :)
}
