/**********************************************************
** Program name: Medusa.cpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: Medusa class member function definitions.
				Member functions include constructor,
				attack, and defense.
***********************************************************/

#include "Medusa.hpp"

/****************************************
 			  Constructor
 Instantiates Medusa object with 0 
 armor points and 8 strength points per
 assignment specifications.
 ***************************************/
Medusa::Medusa(string sName) : Creature()
{
 	setArmor(3);
	setStartingStrPoints(8);
	setStrengthPoints(8);
	wonByGlare = false;
	setName("Medusa");
	setSName(sName);
}
/*******************************************
 		 Constructor (overloaded)
 Instantiates a "dead" Medusa object with 
 0 strength points. This constructor is
 used to transfer a Vampire that is moved
 out of the Creature lineup queue and into 
 the loser stack.
 *******************************************/
Medusa::Medusa(string sName, int strPoints)
	: Creature()
{
 	setArmor(3);
	setStartingStrPoints(8);
	setStrengthPoints(strPoints);
	wonByGlare = false;
	setName("Medusa");
	setSName(sName);
}
/********************************
 		   getWonByGlare
 Gets wonByGlare member variable.
 *********************************/
bool Medusa::getWonByGlare()
{
	return wonByGlare;
}
/*****************************************
 	           setWonByGlare
      Sets wonByGlare member variable.
 ******************************************/
void Medusa::setWonByGlare(bool wonByGlare)
{
	this->wonByGlare = wonByGlare;
}
/******************************************
 			    attack
 Medusa attack is determined by summing
 the roll of 2 six-sided "die". Two random
 numbers are generated and added together
 to provide the return value as such.
 ******************************************/
int Medusa::attack()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;

	return dieRoll1 + dieRoll2;
}
/******************************************
 			    defense 
 Medusa defense is determined by summing
 the roll of 1 six-sided "die". A random
 number between 1 and 6 is returned. 
*******************************************/
int Medusa::defense()
{
	int dieRoll1;
	dieRoll1 = rand() % 6 + 1;

	return dieRoll1;
}
