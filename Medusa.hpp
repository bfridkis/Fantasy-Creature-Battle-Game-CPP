/**********************************************************
** Program name: Medusa.hpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: Medusa class declaration. Medusa is 
				a derived class of the Creature class. Its
				members hold and manipulate data for a 
				fantasy style battle game. Medusa is one
				of 5 characters (represented via subclasses)
				that make up the types of players for the 
				game.
***********************************************************/

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Creature.hpp"

#include<cstdlib>
#include<ctime>

class Medusa : public Creature
{
private:
	bool wonByGlare;
public:
	Medusa(string sName);
	Medusa(string sName, int strPoints);
	bool getWonByGlare();
	void setWonByGlare(bool);
	virtual int attack() override;
	virtual int defense() override;
	virtual ~Medusa(){};
};

#endif /* Medusa_hpp */
