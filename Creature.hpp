/*******************************************
** Program name: Creature.hpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: Creature class declaration.
********************************************/

#ifndef Creature_hpp
#define Creature_hpp

#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::string;

class Creature
{
protected:
	int armor;
	int strengthPoints;
	int startingStrPoints;
	string name;
	string sName;

public:
	Creature(){};
	virtual ~Creature(){};
	int getArmor() const;
	int getStrengthPoints() const;
	string getName() const;
	string getSName() const;
	void setArmor(int armor);
	void setStartingStrPoints
		(int startingStrPoints);
	virtual void setStrengthPoints(int strengthPoints);
	void setName(string name);
	void setSName(string sName);
	//restoreStrength is declared virtual
	//because HarryPotter needs a particular
	//version of the function due to his two
	//lives with different strength points.
	//(Note that setStrengthPoints above is also
	//declared virtual so Harry can set his
	//strength from within his version of the 
	//restoreStrength function.)
	virtual void restoreStrength();
	virtual int attack() = 0;
	virtual int defense() = 0;
};

#endif /* Creature_hpp */
