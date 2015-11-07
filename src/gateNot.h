#include "gate.h"

#ifndef GATE_NOT_H
#define GATE_NOT_H

class GateNot : public Gate
{
public:
	virtual void tick() override;
};

#endif