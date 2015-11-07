#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#ifndef READ_H
#define READ_H

void readHeader(FILE* fd);

std::vector<Gate*> readParts(FILE* fd);

std::vector<Wire*> readWires(FILE* fd);

void connectThem(std::vector<Gate*>* parts, std::vector<Wire*>* wires);

#endif
