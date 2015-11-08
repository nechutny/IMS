#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#include "gate.h"
#include "wire.h"

#include "gateAnd.h"
#include "gateOr.h"
#include "gateNot.h"

#ifndef READ_H
#define READ_H

enum gateType;

gateType hashGate(char* type);

void readHeader(FILE* fd);

std::vector<Gate*> readParts(FILE* fd);

std::vector<Wire*> readWires(FILE* fd);

void connectThem(FILE* fd, std::vector<Gate*>* parts, std::vector<Wire*>* wires);

#endif
