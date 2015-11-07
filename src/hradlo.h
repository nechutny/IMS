/**
 *
 * @author	Stanislav Nechutný - xnechu01
 * @author	Miloš Smutka - xsmutk00
 *
 */
#ifndef HRADLO_H
#define HRADLO_H

class Hradlo;

#include <iostream>
#include <stdbool.h>


class Hradlo
{
	private:
		void *input[];
		unsigned long delay;

	public:
		/**
		 * Block constructor, perform allocations
		 */
		Hradlo();

		/**
		 * Block destructor - deallocate memory
		 */
		~Hradlo();

		/**
		 * Get block rotation
		 *
		 * @return	Number 0-3, radians in positive direction of rotation
		 */
		void Connect(Hradlo* vstup, int cislo);
};

#endif