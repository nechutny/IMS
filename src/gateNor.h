#include "gate.h"

#ifndef GATE_NOR_H
#define GATE_NOR_H

class GateNor : public Gate
{
	public:
		GateNor(FILE* outFile);

		virtual void tick() override;
};

#endif
