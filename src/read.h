#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#ifndef READ_H
#define READ_H

void readHeader(FILE* fd);

std::vector<char> readParts(FILE* fd);

std::vector<char> readWires(FILE* fd);

void connectThem(std::vector<char>* parts, std::vector<char>* wires);

#endif