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

#include "delays.h"

#include "wire.h"

class Gate
{
	protected:
		std::vector<Wire*> input;

		Wire* output;

		FILE* outFile;

		char result;

		unsigned long delay;

	public:
		Gate();

		~Gate();

		/**
		 * Read from inputs and do calculation of result - saved into result
		 */
		virtual void tick();

		void setResult(char result);

		char getValue();

		unsigned long getDelay();

		void connectWire(unsigned int pin, Wire* in);

};

#endif
