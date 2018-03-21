/*******************************************************
** Program name: mainProject4.cpp
** Author: Ben Fridkis
** Date: 5/17/2017
** Description: Main program for executing a battle 
				tournament between fantasy creatures of 
				project 3. Tournament is handled by the 
				executeTournament function.
********************************************************/

#include "battleTournament.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	//Use the time function to 
	//get a "seed" value for srand
	unsigned seed = time(0);
	srand(seed);

	executeTournament();

	return 0;
}
