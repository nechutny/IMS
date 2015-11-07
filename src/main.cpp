#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "read.h"
#include "gate.h"
#include "wire.h"

#include "gateAnd.h"
#include "gateOr.h"
#include "gateNot.h"


void debug()
{
	Gate *gateTmp;

	std::vector<Gate*> parts;
	std::vector<Gate*>::iterator it = parts.end();

	// 0 - AND
	gateTmp = (Gate*)new GateAnd;
	parts.insert(it, gateTmp);

	// 1 - AND
	it = parts.end();
	gateTmp = (Gate*)new GateAnd;
	parts.insert(it, gateTmp);

	// 2 - AND
	it = parts.end();
	gateTmp = (Gate*)new GateAnd;
	parts.insert(it, gateTmp);

	// 3 - OR
	it = parts.end();
	gateTmp = (Gate*)new GateOr;
	parts.insert(it, gateTmp);

	// 4 - NOT
	it = parts.end();
	gateTmp = (Gate*)new GateNot;
	parts.insert(it, gateTmp);


	std::vector<Wire*> wires;
	std::vector<Wire*>::iterator is = wires.end();
	Wire *wireTmp;

	// Cable 0
	wireTmp = new Wire;
	wires.insert(is, wireTmp);
	wireTmp->addInput(parts[1]);
	wireTmp->addOutput(parts[0]);

	// Cable 1
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);
	wireTmp->addInput(parts[4]);
	wireTmp->addInput(parts[3]);
	wireTmp->addOutput(parts[1]);

	// Cable 2
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);
	wireTmp->addInput(parts[0]);
	wireTmp->addInput(parts[3]);
	wireTmp->addOutput(parts[4]);

	// Cable 3
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);
	wireTmp->addInput(parts[0]);
	wireTmp->addInput(parts[1]);
	wireTmp->addOutput(parts[3]);

	while(1)
	{
		for(unsigned i = 0; i < parts.size(); i++)
		{
			((GateAnd*)parts[i])->tick();
		}

		for(unsigned i = 0; i < wires.size(); i++)
		{
			wires[i]->tack();
		}
	}

}

int main(int argc, char* argv[])
{
	if(argc == 2 && strcmp(argv[1],"debug") == 0)
	{
		debug();
		return 0;
	}

		FILE* fd = fopen("input.net", "r");
		
		readHeader(fd);
		std::vector<Gate*> parts = readParts(fd);
		std::vector<Wire*> wires = readWires(fd);
}
