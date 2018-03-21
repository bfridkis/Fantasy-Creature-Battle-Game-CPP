/****************************************************************
** Program name: battle.cpp
** Author: Ben Fridkis
** Date: 5/19/2017
** Description: Provides 3 functions to execute a fantasy 
				battle game for Project 3. The function 
				battle takes two Creature pointers as parameters, 
				determines a random starting player, 
				then calls calls creatureAttack to execute the 
				the battle round. creatureAttack calls the func-
				tion printRoundResult after each turn to display
				the round result and frinal result if the game
				has ended.
*****************************************************************/

#include "battle.hpp"

/*********************************************
			     battle
 This function receives two Creature
 object pointers and uses these objects
 to execute the game 'battle'. Via the 
 principle of polymorphism, Creature 
 behavior will vary depending on the pointed-
 to objects' types. Because Creature is 
 itself an abstract class, there is no 
 actual Creature object instatiated; only
 derived class members will be passed.
*********************************************/
void battle(Creature* c1,
			Creature* c2, 
			char printEachFight,
			char promptBetweenAttacks)
{
	//Variable declared and initialized to
	//declare who will go first randomly.
	//If a random integer is even, c1 goes
	//first, else if the random integer is
	//odd, c2 goes first. Based on which
	//Creature attacks first, the first
	//turn is executed. The creatureAttack 
	//function executes the turn, and the
	//printRoundResults function (called
	//from within creatureAttack) displays
	//the results.
			
	if (rand() % 2 == 0)
	{
		if (printEachFight == 'Y')
		{
			cout << "Creature 1 - " 
				 << c1->getName() << " " 
				 << "\"" << c1->getSName() << "\""
				 << " attacks first." << endl;

			cout << "\nCreature 1 - "
				 << c1->getName() << " \"" 
				 << c1->getSName() << "\"" 
				 << " Starting Profile:\n"
				 << "Strength Points: "
				 << c1->getStrengthPoints() << endl
				 << "Armor Value: "
				 << c1->getArmor() << endl;

			cout << "\nCreature 2 - "
				 << c2->getName() << " \"" 
				 << c2->getSName() << "\""  
				 << " Starting Profile:\n"
				 << "Strength Points: "
				 << c2->getStrengthPoints() << endl
				 << "Armor Value: "
				 << c2->getArmor();
		}		 

		while (c1->getStrengthPoints() > 0 &&
		 	   c2->getStrengthPoints() > 0)
		{
			if (promptBetweenAttacks == 'Y')
			{	
				char ch; 	//Used for input validation, so enter key
							//only needs to be pressed once and characters
							//entered before enter key do not remain in 
							//the input buffer.
				cout << "\n\nPress enter key for next attack.";
				cin.get(ch);
				if (ch != '\n')
				{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}	
			creatureAttack(c1, c2, true, printEachFight, promptBetweenAttacks);

			if (c2->getStrengthPoints() > 0)
			{
				if (promptBetweenAttacks == 'Y')
				{	
					char ch;
					cout << "\n\nPress enter key for next attack.";
					cin.get(ch);
					if (ch != '\n')
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}	
				creatureAttack(c2, c1, false, printEachFight, 
					promptBetweenAttacks);
			}	
		}	
	}	
	else
	{
		if (printEachFight == 'Y')
		{	
			cout << "Creature 2 - " 
				 << c2->getName() << " " 
				 << "\"" << c2->getSName() << "\""
				 << " attacks first." << endl;
			
			cout << "\nCreature 1 - "
				 << c1->getName() << " \"" 
				 << c1->getSName() << "\""
				 << " Starting Profile:\n"
				 << "Strength Points: "
				 << c1->getStrengthPoints() << endl
				 << "Armor Value: "
				 << c1->getArmor() << endl;

			cout << "\nCreature 2 - "
				 << c2->getName() << " \"" 
				 << c2->getSName() << "\""
				 << " Starting Profile:\n"
				 << "Strength Points: "
				 << c2->getStrengthPoints() << endl
				 << "Armor Value: "
				 << c2-> getArmor();	
		}
		
		while (c1->getStrengthPoints() > 0 &&
		 	   c2->getStrengthPoints() > 0)
		{
			if (promptBetweenAttacks == 'Y')
			{	
				char ch;	//Used for input validation, so enter key
							//only needs to be pressed once and characters
							//entered before enter key do not remain in 
							//the input buffer.
				cout << "\n\nPress enter key for next attack.";
				cin.get(ch);
				if (ch != '\n')
				{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}	
			creatureAttack(c2, c1, false, printEachFight, promptBetweenAttacks);

			if(c1->getStrengthPoints() > 0)
			{
				if (promptBetweenAttacks == 'Y')
				{	
					char ch;
					cout << "\n\nPress enter key for next attack.";
					cin.get(ch);
					if (ch != '\n')
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}	
				creatureAttack(c1, c2, true, printEachFight, 
					promptBetweenAttacks);
			}
		}	 
	}

	//If a player has strength points equal to or less than 0,
	//indicate game is over, final winner, and final winner's
	//remaining strength points. Only displays if user indicates
	//printout for each battle.
	if (printEachFight == 'Y')
	{	
		if (c1->getStrengthPoints() <= 0)
		{
			cout << "Round over! Creature 2 - " << c2->getName() 
				 << " \"" << c2->getSName() << "\" has won!\n" << endl;
			cout << "Creature 2 - \"" << c2->getSName() << "'s\""
				 << " Remaining Strength Points Before Restoration: "
				 << c2->getStrengthPoints()
				 << endl;
			c2->restoreStrength();	 

		}
		else if (c2->getStrengthPoints() <= 0)
		{
			cout << "Round over! Creature 1 - " << c1->getName() 
				 << " \"" << c1->getSName() << "\" has won!\n" << endl;
			cout << "Creature 1 - \"" << c1->getSName() << "'s\""
				 << " Remaining Strength Points Before Restoration: "
				 << c1->getStrengthPoints()
				 << endl;
			c1->restoreStrength();	 
		}
	}	
}

/**************************************************
			   	 creatureAttack
 Function to execute an attack. Special features
 of certain characters are taken into account
 using typeid checks prior to die rolls where 
 appropriate. See notes below for more details.
 (Note: This function is used for both player's
 attacks. The parameter c1 is the attacker, while
 c2 is the defender
****************************************************/
void creatureAttack(Creature* attacker,
	     		    Creature* defender, 
			        bool c1Attacked, 
					char printEachFight,
					char promptBetweenAttacks)
{
	//If defemder is a Vampire, the usedGlare member
	//is set false at the beginning of each
	//attack, so glare used can be indicated
	//when the round results are printed at the
	//end of each turn.

	//Declare and initialize attacker attack
	//and defender defense values via member
	//functions. If defender is a Vampire,
	//attack roll is 0 if a random integer
	//is even (50% chance).
	int attackValue;
	int defenseValue = 0;
	int attackDamage = 0;
	if (typeid(*defender) == typeid(Vampire))
	{	
		static_cast<Vampire*>(defender)
			->setUsedCharm(false);
		
		attackValue = attacker->attack();

		if (rand() % 2 == 0)
		{
			defenseValue = 0;
			static_cast<Vampire*>(defender)
				->setUsedCharm(true);
		}
		else
		{
			defenseValue = defender->defense();
		}
	}	
	else
	{
		attackValue = attacker->attack();
		defenseValue = defender->defense();
	}

	//If attacker is a Medusa and the attack
	//roll is 12, flag Medusa's wonByGlare variable.
 	if (typeid(*attacker) ==  typeid(Medusa)
			   && attackValue == 12)
	 { 	  	
		static_cast<Medusa*>(attacker)->setWonByGlare(true);
		
		//If defender is a Vampire and Vampire's usedCharm 
		//is true, set Medusa's wonByGlare back to false.
		//If Vampire's usedCharm is not true, set Vampire's 
		//strength points to 0.
		if (typeid(*defender) == typeid(Vampire))
		{
			if (static_cast<Vampire*>(defender)
					->getUsedCharm())
			{
				static_cast<Medusa*>(attacker)
					->setWonByGlare(false);
			}
			else
			{
				defender->setStrengthPoints(0);
			}
		}
		//If defender is not a Vampire and Medusa has
		//won by glare, set defender strength points to
		//0.
		else
		{
			defender->setStrengthPoints(0);
		}
	 }
	 //If attacker is not a Medusa with an attack value of 12,
	 //attack damage is the attacker's attack value
	 //minus the defender's defense value, minus the
	 //defenders armor value. If this value is greater than
	 //zero, the new strength value for the defender is the
	 //current strength value minus this value.
	 else
	 {
	 	attackDamage = attackValue - defenseValue
		 					- defender->getArmor(); 
							
		//Defense value is only 0 for Vampire using Charm.
		//In this case no update to the defender's strength
		//points occurs.					
		if (attackDamage > 0 && defenseValue > 0)
		{
			defender->setStrengthPoints
				(defender->getStrengthPoints() - attackDamage);
		}
	}
	
	if (printEachFight == 'Y')
	{
		//Function to print the results of each round, and indicate
		//the final winner when one player's strength points reaches
		//zero or less.
		printRoundResults(attacker, defender, attackValue, defenseValue,
			attackDamage, c1Attacked, promptBetweenAttacks);
	}
	//If Harry Potter dies (i.e. strength points go to zero)
	//and it is his first death, his strength points regenerate
	//to 20. (This is handled by the printRoundResult function
	//if the user selects a printout for each round.)
	else if (printEachFight == 'N')
	{
		if (typeid(*defender) == typeid(HarryPotter)
				&& defender->getStrengthPoints() <= 0)
		{
			if (static_cast<HarryPotter*>(defender)
				->getHogwartsUsed() == false)
			{
				defender->setStrengthPoints(20);
				static_cast<HarryPotter*>(defender)
					->setHogwartsUsed(true);
			}
		}
	}	
}	
/***************************************************************
		              printRoundResults
 Prints the results of each attack following attack execution.
****************************************************************/
void printRoundResults(Creature* attacker,
	Creature* defender, int attackValue,
	int defenseValue, int damageDone, bool c1Attacked,
	char promptBetweenAttacks)
{
	cout << endl;
	bool medusaWonByGlare = false;

	if (c1Attacked)
	{
		if (typeid(*attacker) == typeid(Medusa))
		{
			if (static_cast<Medusa*>(attacker)->getWonByGlare())
			{
				cout << "Creature 1 - " << attacker->getName()
					 << " \"" << attacker->getSName() << "\""
					 << " attacked Creature 2 - "
					 << defender->getName() 
					 << " \"" << defender->getSName() << "\".\n"
					 << "Attack Value:   " << attackValue << "\n"
					 << "Special Ability: GLARE - MEDUSA WINS!\n";
	 		
				medusaWonByGlare = true;
			}		 
		}
		if (!medusaWonByGlare)
		{
			cout << "Creature 1 - " << attacker->getName()
				 << " \"" << attacker->getSName() << "\""
				 << " attacked Creature 2 - "
				 << defender->getName() 
				 << " \"" << defender->getSName() << "\".\n"
		 		 << "Attack Value:   " << attackValue << "\n";
			if (defenseValue == 0)
			{
				cout << "Defense Value: CHARM\n";
			}
			else
			{
		 		cout << "Defense Value:  " << defenseValue << "\n";
			}	

			cout << "Armor Value:    " << defender->getArmor() << "\n";
		
			//If defender is Vampire and special ability charm
			//is used, print accordingly. Else, print damage
			//value. (Note: damage value of 0 is only possible
			//when Vampire's charm is used).
			if (defenseValue == 0)
			{
				cout << "Special Ability: VAMPIRE CHARM - 0 DAMAGE.\n";
			}
			else if (damageDone > 0)
			{
				cout << "Damage Value:   " << damageDone << "\n";
			}
			else
			{
				cout << "Damage Value:   0\n";
			}

			//If Harry Potter dies (i.e. strength points go to zero)
			//and it is his first death, his strength points regenerate
			//to 20.
			if (typeid(*defender) == typeid(HarryPotter)
				&& defender->getStrengthPoints() <= 0)
			{
				if (static_cast<HarryPotter*>(defender)
					->getHogwartsUsed() == false)
				{
					defender->setStrengthPoints(20);
					static_cast<HarryPotter*>(defender)
						->setHogwartsUsed(true);
					cout << "Special Ability: HOGWARTS - HARRY HAS DIED "
						 << "BUT HAS COME BACK ALIVE!\n";
				}
			}

			if (defender->getStrengthPoints() > 0)
			{
				cout << "Creature 2 - " << defender->getName() 
					 << " \"" << defender->getSName() << "'s\" "
					 << "remaining strength points: "
					 << defender->getStrengthPoints();
				if ((promptBetweenAttacks == 'N' && 
					typeid(*defender) != typeid(BlueMen))
					|| (promptBetweenAttacks == 'N'
					&& typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() > 8)){cout << endl;} 

				//If defender is BlueMen, indicate reduced Mob if 
				//applicable.
				if (typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() <= 8 
					&& defender->getStrengthPoints() > 4)
				{
					cout << "\nCreature 2 - BLUEMEN MOB REDUCED x1 "
						 <<  "(2 Defense Dice Remaining)";
					if (promptBetweenAttacks == 'N'){cout << endl;}	
				}
				if (typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() <= 4)
				{
					cout << "\nCreature 2 - BLUEMEN MOB REDUCED x2 "
						 << "(1 Defense Die Remaining)";
					if (promptBetweenAttacks == 'N'){cout << endl;}		 
				}
			}	
			else if (defender->getStrengthPoints() <= 0)
			{
				if (promptBetweenAttacks == 'Y'){cout << endl;}
				cout << "\nCreature 2 - " << defender->getName()
					 << " \"" << defender->getSName() << "\""
					 << " has died! Strength Points 0.\n"
					 << endl;
			}
		}	
	}
	else if (!c1Attacked)
	{
		if (typeid(*attacker) == typeid(Medusa))
		{
			if (static_cast<Medusa*>(attacker)->getWonByGlare())
			{
				cout << "Creature 2 - " << attacker->getName()
					 << " \"" << attacker->getSName() << "\""
					 << " attacked Creature 1 - "
					 << defender->getName() 
					 << " \"" << defender->getSName() << "\".\n"
					 << "Attack Value:   " << attackValue << "\n"
					 << "Special Ability: GLARE - MEDUSA WINS!\n";

				medusaWonByGlare = true;	 
			}
		}
		if (!medusaWonByGlare)
		{
			cout << "Creature 2 - " << attacker->getName()
				 << " \"" << attacker->getSName() << "\""
				 << " attacked Creature 1 - "
				 << defender->getName() 
				 << " \"" << defender->getSName() << "\".\n"
		 		 << "Attack Value:   " << attackValue << "\n";
			if (defenseValue == 0)
			{
				cout << "Defense Value: CHARM\n";
			}
			else
			{
		 		cout  << "Defense Value:  " << defenseValue << "\n";
			}

 			cout << "Armor Value:    " << defender->getArmor() << "\n";
		
			//If defender is Vampire and special ability charm
			//is used, print accordingly. Else, print damage
			//value. (Note: damage value of 0 is only possible
			//when Vampire's charm is used).
			if (defenseValue == 0)
			{
				cout << "Special Ability: VAMPIRE CHARM - 0 DAMAGE\n";
			}
			else if (damageDone > 0)
			{
				cout << "Damage Value:   " << damageDone << "\n";
			}
			else
			{
				cout << "Damage Value:   0\n";
			}

			//If Harry Potter dies (i.e. strength points go to zero)
			//and it is his first death, his strength points regenerate
			//to 20.
			if (typeid(*defender) == typeid(HarryPotter)
				&& defender->getStrengthPoints() <= 0)
			{
				if (static_cast<HarryPotter*>(defender)
					->getHogwartsUsed() == false)
				{
					defender->setStrengthPoints(20);
					static_cast<HarryPotter*>(defender)
						->setHogwartsUsed(true);
					cout << "Special Ability: HOGWARTS - HARRY HAS DIED "
						 << "BUT HAS COME BACK ALIVE!\n";
				}
			}

			if (defender->getStrengthPoints() > 0)
			{
				cout << "Creature 1 - " << defender->getName() 
					 << " \"" << defender->getSName() << "'s\" "
					 << "remaining strength points: "
					 << defender->getStrengthPoints();
				if ((promptBetweenAttacks == 'N' && 
					typeid(*defender) != typeid(BlueMen))
					|| (promptBetweenAttacks == 'N'
					&& typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() > 8)){cout << endl;}
				
				//If defender is BlueMen, indicate reduced Mob if 
				//applicable.
				if (typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() <= 8 
					&& defender->getStrengthPoints() > 4)
				{
					cout << "\nCreature 1 - BLUEMEN MOB REDUCED x1 "
						 <<  "(2 Defense Dice Remaining)";
					if (promptBetweenAttacks == 'N'){cout << endl;}	 
				}
				if (typeid(*defender) == typeid(BlueMen)
					&& defender->getStrengthPoints() <= 4)
				{
					cout << "\nCreature 1 - BLUEMEN MOB REDUCED x2 "
						 << "(1 Defense Die Remaining)";
					if (promptBetweenAttacks == 'N'){cout << endl;}	 
				}
			}
			else if (defender->getStrengthPoints() <= 0)
			{
				if (promptBetweenAttacks == 'Y'){cout << endl;}
				cout << "\nCreature 1 - " << defender->getName()
					 << " \"" << defender->getSName() << "\""
					 << " has died! Strength Points 0.\n"
					 << endl;
			}
		}
	}
}