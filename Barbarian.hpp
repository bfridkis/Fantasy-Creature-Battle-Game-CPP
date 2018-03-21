/**********************************************************
** Program name: Barbarian.hpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: Barbarian class declaration. Barbarian is 
				a derived class of the Creature class. Its
				members hold and manipulate data for a 
				fantasy style battle game. Barbarian is one
				of 5 characters (represented via subclasses)
				that make up the types of players for the 
				game.
***********************************************************/

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Creature.hpp"

#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cout;
using std::endl;

class Barbarian : public Creature
{
public:
	Barbarian(string sName);
	Barbarian(string sName, int strPoints);
	virtual int attack() override;
	virtual int defense() override;
	virtual ~Barbarian(){};
};

#endif /* Barbarian_hpp */
