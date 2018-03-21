/**********************************************************
** Program name: Menu.hpp
** Author: Ben Fridkis
** Date: 5/12/2017
** Description: Header file for CreatureMenu.cpp source file.
                Declares CreatureMenu class.
***********************************************************/

#ifndef CreatureMenu_hpp
#define CreatureMenu_hpp

#include "InputValidation.hpp"
#include "MenuInputValidation.hpp"
#include <iostream>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class CreatureMenu
{
protected:
    int numberOfSelections;
    int userSelection;
public:
    static int menu();
    int getNumberOfSelections() const;
    void setNumberOfSelections(int numSelections);
    int getUserSelection() const;
    void setUserSelection(int userSelection);
};

#endif /* CreatureMenu_hpp */