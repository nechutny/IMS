#include "gate.h"

#ifndef GATE_XOR_H
#define GATE_XOR_H

class GateXor : public Gate
{
public:
	virtual void tick() override;
};

#endif