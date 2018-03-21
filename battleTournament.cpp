/***************************************************************
** Program name: battleTournament.cpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: Provides function  to exeute a fantasy 
				battle tournament for Project 4. Builds on 
				project 3 by creating containers of creature
				objects for each player, then executing battle
				between the two containers of creatures until
				all of one player's creatures have died.
				Declares winner, prints remaining creatures 
				and strength points of the winner, and then
				prints the deceased creatures for both players
				(which reside in a stack container for the 
				losing creatures).
***************************************************************/

#include "battleTournament.hpp"

void executeTournament()
{
	cout << "\nWelcome to Fantasy Creature Battle Tournament!"
		 << endl;
	
	char playAgain;

	do
	{
		cout << "\nHow many creatures (per player) would you like "
			 << "to play with?\n(Max is 10)\n" << endl;

		int numCreatures = InputValidation::intInputValidation(10, 1);
		
		//Instantiates CreatureQueue objects for each player as well
		//as a stack object (LoserStack) for the loser creatures.
		CreatureQueue p1, p2;
		LoserStack loserStack;
		
		cout << "\nEnter Creature Information for Player 1:\n"
			 << endl;
		
		//This loop prompts the user to enter names for each
		//creature of player 1's lineup. It then adds them
		//to player 1's CreatureQueue.
		for (int i = 1; i <= numCreatures; i++)
		{
			int creatureType = CreatureMenu::menu();

			cout << "Enter a name for creature " << i << ": ";

			string specificName = InputValidation::
				stringSizeInputValidation(60);

			p1.addBack(specificName, creatureType, true);
		}
		
		cout << "\nEnter Creature Information for Player 2:\n"
			 << endl;
			 
		//This loop prompts the user to enter names for each
		//creature of player 2's lineup. It then adds them
		//to player 2's CreatureQueue.
		for (int i = 1; i <= numCreatures; i++)
		{
			int creatureType = CreatureMenu::menu();

			cout << "Enter a name for creature " << i << ": ";

			string specificName = InputValidation::
				stringSizeInputValidation(60);

			p2.addBack(specificName, creatureType, false);
		}
		
		cout << "\nWould you like to print the results of each attack & battle? "
			 << "(y-yes, n-no): ";
		
		char printEachFight = InputValidation::yOrNInputValidation();
		cout << endl;
		
		char promptBetweenAttacks = 'N';
		if (printEachFight == 'Y')
		{
			cout << "\nWould you like to add a prompt between each attack?\n"
				 <<	"(You will be asked to press the enter key before\n"
				 << "each attack is executed.) (y-yes, n-no):\n";
			
			promptBetweenAttacks = InputValidation::yOrNInputValidation();
			cout << endl;
		}
		
		//Instantiates pointer objects to track the current
		//front node creature of each player lineup (queue).
		//Until one queue is emptied of all creatures, 
		//battle ensues. The winning creature is cycled to the 
		//back of the winning player's queue (via the cycleFrontToBack
		//function of the CreatureQueue class), while the
		//losing creature is removed from the losing player's
		//queue and added to the LoserStack (though technically
		//a new creature is created and added to the creature stack
		//with the same name and starting strength points of 0. See
		//the LoserStack class for more details).
		Creature* p1Creature = p1.getFront(); 
		Creature* p2Creature = p2.getFront();
		int roundNumber = 1;
		while (!p1.isEmpty() && !p2.isEmpty())
		{
			if (printEachFight == 'Y')
			{
				cout << "\nRound " << roundNumber << endl;
				if (promptBetweenAttacks == 'Y'){cout << endl;}
				roundNumber++;
			}
			battle(p1Creature, p2Creature, printEachFight, promptBetweenAttacks);
			if (p1Creature->getStrengthPoints() <= 0)
			{
				Creature* loser = p1.removeFront();
				loserStack.push(loser);
				p2.cycleFrontToBack();
				if(!p1.isEmpty()){p1Creature = p1.getFront();}
				p2Creature = p2.getFront();
			}
			else if (p2Creature->getStrengthPoints() <= 0)
			{	
				
				Creature* loser = p2.removeFront();
				loserStack.push(loser);
				p1.cycleFrontToBack();
				p1Creature = p1.getFront();
				if(!p2.isEmpty()){p2Creature = p2.getFront();}
			}
		}
		
		//When one player has lost all creatures in battle, the
		//tournament ends. The player with creatures remaining
		//wins. Print winner, remaining creatures and strength
		//points, and losers. (Losers are printed last-in first-out.
		//The pop function of the LoserStack class prints the creature
		//name before removing it from the stack.)
		
		if (p1.isEmpty())
		{
			cout << "\nPlayer 2 Wins!!! "
				 << "Player 1 has no creatures remaining.\n\n"
				 << "Player 2's Remaining Creatures:\n\n";
			
			p2.printQueue();

			cout << "Fallen Warriors:\n\n";
			
			while (!loserStack.isEmpty())
			{
				loserStack.pop();
			}
		}
		else if (p2.isEmpty())
		{
			cout << "\nPlayer 1 Wins!!! "
				 << "Player 2 has no creatures remaining.\n\n"
				 << "Player 1's Remaining Creatures:\n\n";
			
			p1.printQueue();

			cout << "Fallen Warriors:\n\n";
			
			while (!loserStack.isEmpty())
			{
				loserStack.pop();
			}
		}
		
		cout << "\nWould you like to play again? (y-yes, n-no): ";
		playAgain = InputValidation::yOrNInputValidation();

	}while(playAgain == 'Y');
	
	cout << "\nThanks for playing!" << endl << endl;
}
