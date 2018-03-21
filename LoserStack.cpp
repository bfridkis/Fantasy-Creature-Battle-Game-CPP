/*************************************************************
** Program name: LoserStack.cpp
** Author: Ben Fridkis
** Date: 5/17/2017
** Description: LoserQueue.cpp source file. Provides the 
**				member function definitions for the 
**				LoserStack class, which provides a singly-
**				linked stack container to hold the losing
**				creatures for fantasy battle tournament play
**				(project 4).
*************************************************************/

#include "LoserStack.hpp"

/*******************************************
    		    Destructor
  LoserStack object destructor. Deallocates 
  all memory assigned to StackNodes and sets
  all pointers null.
*********************************************/
LoserStack::~LoserStack()
{
	StackNode* nodeToDelete = top;
	while (nodeToDelete != nullptr)
	{
		top = top->next;
		delete nodeToDelete->creature;
		delete nodeToDelete;
		nodeToDelete = top;
	}
}
/*******************************************
				  push
 Adds a new StackNode to the LoserStack
 object.
*******************************************/
void LoserStack::push(Creature* loser)
{
	top = new StackNode(loser, top);
}
/**********************************************
				   pop
 Prints top node Creature specific name and 
 then removes top node.
***********************************************/
void LoserStack::pop()
{
	if (top == nullptr)
	{
		throw LoserStack::Underflow();
	}
	else
	{
		string loserName = top->creature->getSName();
		cout << loserName << endl;
		StackNode* popped = top;
		top = top->next;
		delete popped->creature;
		delete popped;
	}
}
/*******************************************
				  isEmpty
 Returns boolean value true to designate an
 empty stack. Otherwise returns false.
*******************************************/
bool LoserStack::isEmpty() const
{
	return top == nullptr;
}