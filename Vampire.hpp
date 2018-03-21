/**********************************************************
** Program name: Vampire.hpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: Vampire class declaration. Vampire is 
				a derived class of the Creature class. Its
				members hold and manipulate data for a 
				fantasy style battle game. Vampire is one
				of 5 characters (represented via subclasses)
				that make up the types of players for the 
				game.
***********************************************************/

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Creature.hpp"

#include<cstdlib>
#include<ctime>

class Vampire : public Creature
{
private:
	bool usedCharm;
public:
	Vampire(string sName);
	Vampire(string sName, int strPoints);
	bool getUsedCharm();
	void setUsedCharm(bool);
	virtual int attack() override;
	virtual int defense() override;
	virtual ~Vampire(){};
};

#endif /* Vampire_hpp */
