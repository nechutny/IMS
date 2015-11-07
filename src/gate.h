/**
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 *
 */
#ifndef GATE_H
#define GATE_H

class Gate;

#include <stdbool.h>

#include <iostream>
#include <vector>

#include "wire.h"

class Gate
{
	private:
		std::vector<Wire*> input;

		Wire* output;

		char result;

		unsigned long long delay;

	public:
		Gate();

		~Gate();

		/**
		 * Read from inputs and do calculation of result - saved into result
		 */
		void tick();

		char getValue();
		/* {
		 *	return result;
		 * }
		 */

		unsigned long long getDelay();
		/* {
		 * 	return delay;
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