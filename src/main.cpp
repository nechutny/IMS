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

	std::vector<Gate*> gates;
	std::vector<Gate*>::iterator it = gates.end();

	// 0 - AND
	gateTmp = (Gate*)new GateAnd;
	gates.insert(it, gateTmp);

	// 1 - AND
	it = gates.end();
	gateTmp = (Gate*)new GateAnd;
	gates.insert(it, gateTmp);

	// 2 - AND
	it = gates.end();
	gateTmp = (Gate*)new GateAnd;
	gates.insert(it, gateTmp);

	// 3 - OR
	it = gates.end();
	gateTmp = (Gate*)new GateOr;
	gates.insert(it, gateTmp);

	// 4 - NOT
	it = gates.end();
	gateTmp = (Gate*)new GateNot;
	gates.insert(it, gateTmp);


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
	gates[0]->connectWire(0, wires[0]);
	gates[0]->connectWire(1, wires[2]);
	gates[0]->connectWire(2, wires[3]);

	// Connect 1 AND
	gates[1]->connectWire(0, wires[1]);
	gates[1]->connectWire(1, wires[0]);
	gates[1]->connectWire(2, wires[3]);

	// Connect 3 OR
	gates[3]->connectWire(0, wires[3]);
	gates[3]->connectWire(1, wires[2]);
	gates[3]->connectWire(2, wires[1]);

	// Connect 4 NOT
	gates[4]->connectWire(0, wires[2]);
	gates[4]->connectWire(1, wires[1]);

	// Simulate
	while(1)
	{
		// Compute new outputs
		for(unsigned i = 0; i < gates.size(); i++)
		{
			gates[i]->tick();
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
	std::vector<Gate*> gates = readParts(fd);
	std::vector<Wire*> wires = readWires(fd);
	connectThem(fd, &gates, &wires);

	while(1)
	{
		// Compute new outputs
		for(unsigned i = 0; i < gates.size(); i++)
		{
			gates[i]->tick();
		}

		// Add them to wires
		for(unsigned i = 0; i < wires.size(); i++)
		{
			wires[i]->tack();
		}
	}
}
