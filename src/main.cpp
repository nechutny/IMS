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

	// Cable 1
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);

	// Cable 2
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);

	// Cable 3
	wireTmp = new Wire;
	is = wires.end();
	wires.insert(is, wireTmp);

	// Connect 0 AND
	parts[0]->connectWire(0, wires[0]);
	parts[0]->connectWire(1, wires[2]);
	parts[0]->connectWire(2, wires[3]);

	// Connect 1 AND
	parts[1]->connectWire(0, wires[1]);
	parts[1]->connectWire(1, wires[0]);
	parts[1]->connectWire(2, wires[3]);

	// Connect 3 OR
	parts[3]->connectWire(0, wires[3]);
	parts[3]->connectWire(1, wires[2]);
	parts[3]->connectWire(2, wires[1]);

	// Connect 4 NOT
	parts[4]->connectWire(0, wires[2]);
	parts[4]->connectWire(1, wires[1]);

	// Simulate
	while(1)
	{
		// Compute new outputs
		for(unsigned i = 0; i < parts.size(); i++)
		{
			parts[i]->tick();
		}

		// Add them to wires
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
		connectThem(fd, &parts, &wires);
}
