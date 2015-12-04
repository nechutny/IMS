#include "gate.h"

#ifndef GATE_OR_H
#define GATE_OR_H

class GateOr : public Gate
{
	public:
		GateOr(FILE* outFile);

		virtual void tick() override;
};

#endif