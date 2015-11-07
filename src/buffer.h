/**
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 *
 */
#ifndef BUFFER_H
#define BUFFER_H

class Buffer;

#include <iostream>
#include <vector>

#include <stdbool.h>


class Buffer
{
	private:
		char* data;
		unsigned long offset;
		unsigned long size;

	public:
		Buffer();

		~Buffer();

		char getValue(int delay = 0);
		/* {
		 *
		 * }
		 */

		void setValue(char val);
		/* {
		 *
		 * }
		 */

		void increaseSize(unsigned long size);


};

#endif