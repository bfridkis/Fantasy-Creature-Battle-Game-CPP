/**********************************************************
** Program name: HarryPotter.cpp
** Author: Ben Fridkis
** Date: 5/18/2017
** Description: HarryPotter class member function definitions.
				Member functions include constructor,
				attack, and defense.
***********************************************************/

#include "HarryPotter.hpp"

/****************************************
 			  Constructor
 Instantiates HarryPotter object with 0 
 armor points and 10 strength points per
 assignment specifications.
 ***************************************/
HarryPotter::HarryPotter(string sName)
	: Creature()
{
 	setArmor(0);
	setStrengthPoints(10);
	setHogwartsUsed(false);
	setName("Harry Potter");
	setSName(sName);
}
/***********************************************
 		   Constructor (overloaded)
 Instantiates a "dead" HarryPotter object with 
 0 strength points. This constructor is
 used to transfer a Vampire that is moved
 out of the Creature lineup queue and into 
 the loser stack.
 ************************************************/
HarryPotter::HarryPotter(string sName,
int strPoints) : Creature()
{
 	setArmor(0);
	setStrengthPoints(strPoints);
	setHogwartsUsed(true);
	setName("Harry Potter");
	setSName(sName);
}
/****************************************
 			  getHogwartsUsed
   Gets hogwartsUsed member variable.
 ***************************************/
bool HarryPotter::getHogwartsUsed()
{
 	return hogwartsUsed;
}
/**************************************************
		          setHogwartsUsed
         Sets hogwartsUsed member variable.
 ***************************************************/
void HarryPotter::setHogwartsUsed(bool hogwartsUsed)
{
 	this->hogwartsUsed = hogwartsUsed;
}
/******************************************
 	         setStrengthPoints
 Function to set armor member variable.
*******************************************/
void HarryPotter::setStrengthPoints
	(int strengthPoints)
{
	this->strengthPoints = strengthPoints;
}
/******************************************
 			    attack
 HarryPotter attack is determined by summing
 the roll of 2 six-sided "die". Two random
 numbers are generated and added together
 to provide the return value as such.
 ******************************************/
int HarryPotter::attack()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;

	return dieRoll1 + dieRoll2;
}
/******************************************
 			    defense 
 HarryPotter defense is determined by summing
 the roll of 2 six-sided "die". Two random
 numbers are generated and added together
 to provide the return value as such.
 ******************************************/
int HarryPotter::defense()
{
	int dieRoll1, dieRoll2;
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;

	return dieRoll1 + dieRoll2;
}
/**********************************************
   	         restoreStrength
 Function to restore strength value after
 a victor is returned to the CreatureQueue
 (tournament play - project 4). There is a
 1 in 5 chance the strength value is restored
 0%, 1 in 5 chance the strength value is 
 restored 25%, 1 in 5 chance the strength 
 value is restored 50%, 1 in 5 chance the 
 strength value is restored 75%, and a 1 in 5
 chance the strength value is restored to 100%.
***********************************************/
void HarryPotter::restoreStrength()
{	
	if (hogwartsUsed)
	{
		int random = rand() % 5 + 1;
		
		//The restore value is calculated by 
		//determining the deficit from the starting
		//strength points, multiplying it by the 
		//appropriate percentage based on the random
		//integer generator, and adding to the 
		//current strength points (the decimal value
		//of the multiplication result is truncated
		//before the result is added to the strength
		//points). (If the random int generator outputs 
		//a 1, no restoration occurs. If the random int 
		//generator outputs a 5, full restoration to 
		//starting strength points occurs.
		if (random == 1)
		{
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 0%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
		else if (random == 2)
		{
			setStrengthPoints(((startingStrPointsLife2 - 
				getStrengthPoints()) * 0.25)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 25%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
		else if (random == 3)
		{
			setStrengthPoints(((startingStrPointsLife2 - 
				getStrengthPoints()) * 0.50)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 50%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;	
		}
		else if (random == 4)
		{
			setStrengthPoints(((startingStrPointsLife2 - 
				getStrengthPoints()) * 0.75)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 75%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
		else
		{
			setStrengthPoints(startingStrPointsLife2);
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 100%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
	}
	else if (!hogwartsUsed)
	{
		int random = rand() % 5 + 1;
		
		//The restore value is calculated by 
		//determining the deficit from the starting
		//strength points, multiplying it by the 
		//appropriate percentage based on the random
		//integer generator, and adding to the 
		//current strength points (the decimal value
		//of the multiplication result is truncated
		//before the result is added to the strength
		//points). (If the random int generator outputs 
		//a 1, no restoration occurs. If the random int 
		//generator outputs a 5, full restoration to 
		//starting strength points occurs.
		if (random == 1)
		{
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 0%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
		else if (random == 2)
		{
			setStrengthPoints(((startingStrPointsLife1 - 
				getStrengthPoints()) * 0.25)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 25%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}
		else if (random == 3)
		{
			setStrengthPoints(((startingStrPointsLife1 - 
				getStrengthPoints()) * 0.50)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 50%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;	
		}
		else if (random == 4)
		{
			setStrengthPoints(((startingStrPointsLife1 - 
				getStrengthPoints()) * 0.75)
				+ getStrengthPoints());
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 75%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;	
		}
		else
		{
			setStrengthPoints(startingStrPointsLife1);
			cout << "Restore Value (% Deficit to Full Strength - "
				 << "Decimal Value Truncated): 100%\n"
				 << "Strength Points After Restoration: "
				 << getStrengthPoints() << endl << endl;
		}	
	}
}
