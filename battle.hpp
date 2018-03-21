/*************************************************************
** Program name: battle.hpp
** Author: Ben Fridkis
** Date: 5/19/2017
** Description: Header file to declare function prototypes 
				needed to execute battle between 2 Creatures
				(of the Creature class) for project 3's 
				fantasy battle game.
*************************************************************/

#ifndef battle_hpp
#define battle_hpp

#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void battle(Creature* c1, Creature* c2, 
			char printEachFight,
			char promptBetweenAttacks);

void creatureAttack(Creature* attacker,
					Creature* defender,
					bool c1Attacked,
					char printEachFight,
					char promptBetweenAttacks);
					
void printRoundResults(Creature* c1,
	Creature* c2, int attackValue,
	int defenseValue, int damageDone, bool c1Attacked,
	char promptBetweenAttacks);

#endif /* battle_hpp */	
