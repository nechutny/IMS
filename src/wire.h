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

		unsigned long maxDelay;

	public:
		Wire();

		~Wire();

		/**
		 * Read from gates and store new value into buffer - must be called after tick on all gates
		 */
		void tack();

		char getValue(int delay = 0);

		void notifyDelay(unsigned long delay);

		void addInput(Gate *in);

		void addOutput(Gate *in);

};

#endif