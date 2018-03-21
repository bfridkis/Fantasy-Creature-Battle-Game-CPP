/**********************************************************
** Program name: HarryPotter.hpp
** Author: Ben Fridkis
** Date: 5/5/2017
** Description: HarryPotter class declaration. HarryPotter is 
				a derived class of the Creature class. Its
				members hold and manipulate data for a 
				fantasy style battle game. HarryPotter is one
				of 5 characters (represented via subclasses)
				that make up the types of players for the 
				game.
***********************************************************/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Creature.hpp"

#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cout;
using std::endl;

class HarryPotter : public Creature
{
private:
	bool hogwartsUsed;
	int startingStrPointsLife1 = 10;
	int startingStrPointsLife2 = 20;
public:
	HarryPotter(string sName);
	HarryPotter(string sName,
		int strPoints);
	bool getHogwartsUsed();
	void setHogwartsUsed(bool);
	virtual void setStrengthPoints
		(int strengthPoints);
	virtual int attack() override;
	virtual int defense() override;
	virtual void restoreStrength() override;
	virtual ~HarryPotter(){};
};

#endif /* HarryPotter_hpp */
