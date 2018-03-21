/******************************************************
** Program name: LoserStack.hpp
** Author: Ben Fridkis
** Date: 5/17/2017
** Description: Header file for LoserStack.cpp source 
				file. Declares the LoserStack class 
				which provides a singly-linked 
				stack container that holds the losing 
				creatures (Project 4).
*******************************************************/

#ifndef LoserStack_hpp
#define LoserStack_hpp

#include <iostream>
#include "Creature.hpp"
using std::cout;
using std::endl;

class LoserStack
{
private:
	struct StackNode
	{
		Creature* creature;
		StackNode* next;
		StackNode(Creature* loser,
			StackNode* next1 = nullptr)
			{
				creature = loser;
				next = next1;
			}
	};
	StackNode* top;

public:
	LoserStack(){top = nullptr;}
	~LoserStack();
	void push(Creature*);
	void pop();
	bool isEmpty() const;
	class Underflow{};
};

#endif /* LoserStack_hpp */
