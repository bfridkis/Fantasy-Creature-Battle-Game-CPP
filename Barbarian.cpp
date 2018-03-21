/**********************************************************
** Program name: Barbarian.cpp
** Author: Ben Fridkis
** Date: 5/3/2017
** Description: Barbarian class member function definitions.
				Member functions include constructor,
				attack, and defense.
***********************************************************/

#include "Barbarian.hpp"

/**********************************************
 			  Constructor
 Instantiates Barbarian object with 0 armor
 points and 12 strength points per assignment 
 specifications.
 **********************************************/
Barbarian::Barbarian(string sName) : Creature()
{
 	setArmor(0);
	setStartingStrPoints(12);
	setStrengthPoints(12);
	setName("Barbarian");
	setSName(sName);
}
/*******************************************
 		 Constructor (overloaded)
 Instantiates a "dead" Barbarian object with 
 0 strength points. This constructor is
 used to transfer a Vampire that is moved
 out of the Creature lineup queue and into 
 the loser stack.
 *******************************************/
Barbarian::Barbarian(string sName, int strPoints)
	: Creature()
{
 	setArmor(0);
	setStartingStrPoints(12);
	setStrengthPoints(strPoints);
	setName("Barbarian");
	setSName(sName);
}
/******************************************
 			    attack
 Barbarian attack is determined by summing
 the roll of 2 six-sided "die". Two random
 numbers are generated and added together
 to provide the return value as such.
 ******************************************/
int Barbarian::attack()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;

	return dieRoll1 + dieRoll2;
}
/******************************************
 			    defense 
 Barbarian defense is determined by summing
 the roll of 2 six-sided "die". Two random
 numbers are generated and added together
 to provide the return value as such.
 ******************************************/
int Barbarian::defense()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;

	return dieRoll1 + dieRoll2;
}
