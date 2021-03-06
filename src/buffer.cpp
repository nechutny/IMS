#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>


Buffer::Buffer()
{
	size = 1;
	offset = 0;

	data = (char*)calloc(100, sizeof(char));
}

Buffer::~Buffer()
{
	free(data);
}

char Buffer::getValue(int delay)
{
	unsigned int off = ((size+offset-delay)%size);
	//printf("Position: %d, Delay: %d, Size: %d --> %d \n", offset, delay, size, off);
	return data[ off ];
}

void Buffer::setValue(char val)
{
	offset = (offset+1) % size;
	data[ offset ] = val;
}


void Buffer::increaseSize(unsigned long num)
{
	if(num > size)
	{
		data = (char*)realloc(data, sizeof(char)*num);
		memset(data, 0, sizeof(char)*num);
		size = num;
	}

}
