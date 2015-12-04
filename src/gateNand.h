#include "gate.h"

#ifndef GATE_NAND_H
#define GATE_NAND_H

class GateNand : public Gate
{
	public:
		GateNand(FILE* outFile);

		virtual void tick() override;
};

#endif
