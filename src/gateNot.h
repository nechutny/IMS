#include "gate.h"

#ifndef GATE_NOT_H
#define GATE_NOT_H

class GateNot : public Gate
{
	public:
		GateNot(FILE* outFile);

		virtual void tick() override;
};

#endif