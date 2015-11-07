#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>


Buffer::Buffer()
{
	size = 100;
	offset = 0;

	data = (char*)calloc(100, sizeof(char));
}

Buffer::~Buffer()
{
	free(data);
}

char Buffer::getValue(int delay)
{
	return data[ (offset - delay) % size ];
}

void Buffer::setValue(char val)
{
	data[ ++offset ] = val;
}


void Buffer::increaseSize(unsigned long size)
{
	// oh shit
}