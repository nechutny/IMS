#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "read.h"
#include "gate.h"
#include "wire.h"


int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "usage ./ims file.net simTime\n");
		return 1;
	}

	FILE* fd = fopen(argv[1], "r");

	if(fd == NULL)
	{
		fprintf(stderr, "File not found!");
		return 2;
	}

	FILE* output = fopen("output.csv","w+");
	if(output == NULL)
	{
		fprintf(stderr, "Can't create output file.");
		return 3;
	}

	fprintf(output, "time");

	readHeader(fd);
	std::vector<Gate*> gates = readParts(fd, output);
	std::vector<Wire*> wires = readWires(fd);
	connectThem(fd, &gates, &wires);

	unsigned long long time = 0;
	unsigned long long simTime = atoi(argv[2]);

	if(simTime == 0)
	{
		fprintf(stderr, "simTime must be greater than zero");
		return 4;
	}




	while(time < simTime)
	{
		fprintf(output, "\n%lld", time);

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

		//fprintf(output, "\n");

		time++;
	}
}
