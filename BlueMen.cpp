/**********************************************************
** Program name: BlueMen.cpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: BlueMen class member function definitions.
				Member functions include constructor,
				attack, and defense.
***********************************************************/

#include "BlueMen.hpp"

/****************************************
 			  Constructor
 Instantiates BlueMen object with 3 
 armor points and 12 strength points per
 assignment specifications.
 ***************************************/
BlueMen::BlueMen(string sName) : Creature()
{
 	setArmor(3);
	setStartingStrPoints(12);
	setStrengthPoints(12);
	setName("Blue Men");
	setSName(sName);
}
/*******************************************
 		 Constructor (overloaded)
 Instantiates a "dead" BlueMen object with 
 0 strength points. This constructor is
 used to transfer a Vampire that is moved
 out of the Creature lineup queue and into 
 the loser stack.
 *******************************************/
BlueMen::BlueMen(string sName, int strPoints) 
	: Creature()
{
 	setArmor(3);
	setStartingStrPoints(12);
	setStrengthPoints(strPoints);
	setName("Blue Men");
	setSName(sName);
}
/******************************************
 			      attack
 BlueMen attack is determined by outputting
 the result of a random number in the range
 of 1 to 20 (i.e. rolling 2 ten-sided
 die). Two random numbers between 1 and 10
 are added for the return value as such.
 ******************************************/
int BlueMen::attack()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 10 + 1;
	dieRoll2 = rand() % 10 + 1;
	return dieRoll1 + dieRoll2;
}
/********************************************
 			    defense
 BlueMen defense is determined by outputting
 the result of a random number in the range
 of 1 to 18 (i.e. rolling 3 six-sided
 die) if strength points are greater than 8.
 If strength points are between 5 and 8, 
 the defense result is a random number 
 between 1 and 12 (i.e. rolling 2 six-sided
 die). If strength points are equal to or
 less than 4, defense is given by a random
 number between 1 and 6 (i.e. rolling 1 six-
 sided die). Random numbers are provided 
 according these criteria for the return 
 value.
 ********************************************/
int BlueMen::defense()
{
	if (getStrengthPoints() > 8)
	{
		int dieRoll1, dieRoll2, dieRoll3;
		dieRoll1 = rand() % 6 + 1;
		dieRoll2 = rand() % 6 + 1;
		dieRoll3 = rand() % 6 + 1;

		return dieRoll1 + dieRoll2 + dieRoll3;
	}
	else if (getStrengthPoints() > 4 
			 && getStrengthPoints() <= 8)
	{
		int dieRoll1, dieRoll2;
		dieRoll1 = rand() % 6 + 1;
		dieRoll2 = rand() % 6 + 1;

		return dieRoll1 + dieRoll2;
	}
	else
	{
		int dieRoll1;
		dieRoll1 = rand() % 6 + 1;

		return dieRoll1;
	}
}
