/**********************************************************
** Program name: BlueMen.hpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: BlueMen class declaration. BlueMen is 
				a derived class of the Creature class. Its
				members hold and manipulate data for a 
				fantasy style battle game. BlueMen is one
				of 5 characters (represented via subclasses)
				that make up the types of players for the 
				game.
***********************************************************/

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Creature.hpp"

#include<cstdlib>
#include<ctime>

class BlueMen : public Creature
{
public:
	BlueMen(string sName);
	BlueMen(string sName, int strPoints);
	virtual int attack() override;
	virtual int defense() override;
	virtual ~BlueMen(){};
};

#endif /* BlueMen_hpp */
