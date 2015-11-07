#include "gate.h"

#ifndef GATE_OR_H
#define GATE_OR_H

class GateOr : public Gate
{
	public:
	virtual void tick() override;
};

#endif