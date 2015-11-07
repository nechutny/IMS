/**
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 *
 */
#ifndef WIRE_H
#define WIRE_H

class Wire;

#include <iostream>
#include <vector>

#include <stdbool.h>

#include "gate.h"
#include "buffer.h"


class Wire
{
	private:
		std::vector<Gate*> input;
		std::vector<Gate*> output;

		Buffer buffer;

		unsigned long long maxDelay;

	public:
		Wire();

		~Wire();

		/**
		 * Read from gates and store new value into buffer - must be called after tick on all gates
		 */
		void tack();

		char getValue(int delay = 0);
		/* {
		 *
		 * }
		 */

		void notifyDelay(unsigned long long delay);
		/* {
		 * 	if(maxDelay < delay)
		 * 	{
		 * 		maxDelay = delay;
		 * 		buffer->increaseSize(maxDelay);
		 * 	}
		 * }
		 */

		void connectWire(unsigned int pin, Wire* in);
		/* {
		 *	if(pin == 0)
		 *	{
		 *		output = in;
		 *		wire->notifyDelay(delay);
		 *	}
		 *	else
		 *	{
		 *		input[ pin ] = in;
		 *	}
		 * }
		 */

};

#endif