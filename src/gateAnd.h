#include "gate.h"

#ifndef GATE_AND_H
#define GATE_AND_H

class GateAnd : public Gate
{
	public:
		GateAnd(FILE* outFile);

		virtual void tick() override;


};

#endif
