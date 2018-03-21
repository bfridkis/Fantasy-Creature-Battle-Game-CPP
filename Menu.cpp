/*************************************************************
** Program name: Menu.cpp
** Author: Ben Fridkis
** Date: 5/12/2017
** Description: Member function definitions for menu class.
                Provides Project 3 specific prompts for
				starting game or quitting program.
**************************************************************/

#include "Menu.hpp"

/**************************************************
                       menu
  Prompts user to enter menu selection and returns
  user selection.  
 **************************************************/
int Menu::menu()
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
    
	cout << "\nEnter Menu Selection:\n" << endl;
	
	//Project 3 specific prompts.
    cout << "1. Play Game." << endl;
    cout << "2. Quit." << endl;
    
    userChoice = thisMenuInputValidation->menuInputValidation
        (2);
	
	userSelection = userChoice;
    
    return userSelection;
}
/**********************************************
              getNumberOfSelections
     Gets numberOfSelections member variable.
 **********************************************/
int Menu::getNumberOfSelections() const
{
    return numberOfSelections;
}
/*******************************************
              setNumberOfSelections
  Sets numberOfSelections member variable.
 *******************************************/
void Menu::setNumberOfSelections(int numberOfSelections)
{
    this->numberOfSelections = numberOfSelections;
}
/******************************************
               getuserSelection
      Gets userSelection member variable.
 ******************************************/
int Menu::getUserSelection() const
{
    return userSelection;
}
/**************************************
              setUserSelection
  Sets userSelection member variable.
 **************************************/
void Menu::setUserSelection(int userSelection)
{
    this->userSelection = userSelection;
}
