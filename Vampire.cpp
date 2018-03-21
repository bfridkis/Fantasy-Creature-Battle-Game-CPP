/**********************************************************
** Program name: Vampire.cpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: Vampire class member function definitions.
				Member functions include constructor,
				attack, and defense.
***********************************************************/

#include "Vampire.hpp"

/*******************************************
 			  Constructor
 Instantiates Vampire object with 1 
 armor points and 18 strength points per
 assignment specifications.
 *******************************************/
Vampire::Vampire(string sName) : Creature()
{
    setArmor(1);
	setStartingStrPoints(18);
	setStrengthPoints(18);
	usedCharm = false;
	setName("Vampire");
	setSName(sName);
}
/*******************************************
 		 Constructor (overloaded)
 Instantiates a "dead" Vampire object with 
 0 strength points. This constructor is
 used to transfer a Vampire that is moved
 out of the Creature lineup queue and into 
 the loser stack.
 *******************************************/
Vampire::Vampire(string sName, int strPoints) 
	: Creature()
{
    setArmor(1);
	setStartingStrPoints(18);
	setStrengthPoints(strPoints);
	usedCharm = false;
	setName("Vampire");
	setSName(sName);
}
/********************************
		   getUsedCharm
  Gets usedCharm member variable.
 *********************************/
bool Vampire::getUsedCharm()
{
	return usedCharm;
}
/******************************************
	           setUsedCharm
      Sets usedCharm member variable.
* *****************************************/
void Vampire::setUsedCharm(bool usedCharm)
{
	this->usedCharm = usedCharm;
}
/******************************************
 			    attack
 Vampire attack is determined by outputting
 the result of a random number in the range
 of 1 to 12 (i.e. rolling 1 twelve-sided
 die). A random number between 1 and 12 is
 provided for the return value as such.
 ******************************************/
int Vampire::attack()
{
	int dieRoll;
	dieRoll = rand() % 12 + 1;
	
	return dieRoll;
}
/******************************************
 			    defense
 Vampire defense is determined by outputting
 the result of a random number in the range
 of 1 to 6 (i.e. rolling 1 six-sided
 die). A random number between 1 and 12 is
 provided for the return value as such.
 ******************************************/
int Vampire::defense()
{
	int dieRoll;
	dieRoll = rand() % 6 + 1;
	
	return dieRoll;
}
