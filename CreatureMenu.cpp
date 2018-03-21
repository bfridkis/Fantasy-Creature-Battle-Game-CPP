/*************************************************************
** Program name: Menu.cpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: Member function definitions for menu class.
                Provides Project 3 & 4 specific prompts for
				creature selection.
**************************************************************/

#include "CreatureMenu.hpp"

/**************************************************
                       menu
  Prompts user to enter menu selection and returns
  user selection.  
 **************************************************/
int CreatureMenu::menu()
{
    int userChoice;
	
    //This smart pointer assignment statement will dynamically
	//create a local MenuInputValidation object whose member
	//function will return validated input (line 49). The shared 
	//pointer's reference count will decrease to 0 when the object 
	//goes out of scope, and the managed object's memory will be 
	//automatically deallocated.
	shared_ptr<MenuInputValidation> thisMenuInputValidation =
		make_shared<MenuInputValidation>();
    
	
		cout << "Choose Creature Type:\n" << endl;
	
		cout << "1. Vampire" << endl
			 << "2. Barbarian" << endl
			 << "3. Blue Men" << endl
			 << "4. Medusa" << endl
			 << "5. Harry Potter" << endl;
    
    userChoice = thisMenuInputValidation->menuInputValidation
        (5);
	
	return userChoice;
}
/**********************************************
              getNumberOfSelections
     Gets numberOfSelections member variable.
 **********************************************/
int CreatureMenu::getNumberOfSelections() const
{
    return numberOfSelections;
}
/*******************************************
              setNumberOfSelections
  Sets numberOfSelections member variable.
 *******************************************/
void CreatureMenu::setNumberOfSelections
	(int numberOfSelections)
{
    this->numberOfSelections = numberOfSelections;
}
/******************************************
               getuserSelection
      Gets userSelection member variable.
 ******************************************/
int CreatureMenu::getUserSelection() const
{
    return userSelection;
}
/**************************************
              setUserSelection
  Sets userSelection member variable.
 **************************************/
void CreatureMenu::setUserSelection
	(int userSelection)
{
    this->userSelection = userSelection;
}
