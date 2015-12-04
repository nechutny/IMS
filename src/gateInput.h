#include "gate.h"

#ifndef GATE_INPUT_H
#define GATE_INPUT_H

class GateInput : public Gate
{
	public:
		GateInput(FILE* outFile);

		virtual void tick() override;
};

#endif
