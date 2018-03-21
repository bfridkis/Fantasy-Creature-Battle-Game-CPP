/**********************************************************
** Program name: Creature.cpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: Creature class implementation file. This is
				the abstract base class for various derived
				classes which will server as the basis for 
				characters in fantasy battle game. The 
				attributes common to all characters include
				armor and strength points, which are 
				established here in the base class.
***********************************************************/

#include "Creature.hpp"

/***************************************
			   getArmor
 Function to get member variable armor.
***************************************/
int Creature::getArmor() const
{	
	return armor;
}
/***********************************************
   	            getStrengthPoints
 Function to get member variable strengthPoints.
************************************************/
int Creature::getStrengthPoints() const
{	
	return strengthPoints;
}
/**************************************
   	            getName
 Function to get member variable name.
****************************************/
string Creature::getName() const
{	
	return name;
}
/*******************************************
   	            getSName
 Function to get member variable sName.
 ("sName" denotes specific name, the 
 user assigned name given during tournament
 play for project 4.)
********************************************/
string Creature::getSName() const
{	
	return sName;
}
/**************************************
 	           setArmor
 Function to set armor member variable.
***************************************/
void Creature::setArmor(int armor)
{
	this->armor = armor;
}
/**************************************************
 	           setStartingStrPoints
 Function to set startingStrPoints member variable.
***************************************************/
void Creature::setStartingStrPoints
	(int startingStrPoints)
{
	this->startingStrPoints = startingStrPoints;
}
/******************************************
 	         setStrengthPoints
 Function to set armor member variable.
*******************************************/
void Creature::setStrengthPoints
	(int strengthPoints)
{
	this->strengthPoints = strengthPoints;
}
/**************************************
   	             setName
 Function to set member variable name.
***************************************/
void Creature::setName(string name)
{	
	this->name = name;
}
/***************************************
   	            setSName
 Function to set member variable sName.
****************************************/
void Creature::setSName(string sName)
{	
	this->sName = sName;
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
 chance the strength value is restored to 100%
***********************************************/
void Creature::restoreStrength()
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
		setStrengthPoints(((startingStrPoints - 
			strengthPoints) * 0.25)
			+ strengthPoints);
		cout << "Restore Value (% Deficit to Full Strength - "
			 << "Decimal Value Truncated): 25%\n"
			 << "Strength Points After Restoration: "
			 << getStrengthPoints() << endl << endl;	
	}
	else if (random == 3)
	{
		setStrengthPoints(((startingStrPoints - 
			strengthPoints) * 0.50)
			+ strengthPoints);
		cout << "Restore Value (% Deficit to Full Strength - "
			 << "Decimal Value Truncated): 50%\n"
			 << "Strength Points After Restoration: "
			 << getStrengthPoints() << endl << endl;	
	}
	else if (random == 4)
	{
		setStrengthPoints(((startingStrPoints - 
			strengthPoints) * 0.75)
			+ strengthPoints);
		cout << "Restore Value (% Deficit to Full Strength - "
			 << "Decimal Value Truncated): 75%\n"
			 << "Strength Points After Restoration: "
			 << getStrengthPoints() << endl << endl;
	}
	else
	{
		setStrengthPoints(startingStrPoints);
		cout << "Restore Value (% Deficit to Full Strength - "
			 << "Decimal Value Truncated): 100%\n"
			 << "Strength Points After Restoration: "
			 << getStrengthPoints() << endl << endl;
	}
}