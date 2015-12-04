#include "gate.h"

#ifndef GATE_XOR_H
#define GATE_XOR_H

class GateXor : public Gate
{
	public:
		GateXor(FILE* outFile);

		virtual void tick() override;
};

#endif