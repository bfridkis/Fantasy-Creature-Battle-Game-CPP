/**********************************************************
** Program name: CreatureQueue.hpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: Header file for CreatireQueue.cpp source 
				file. Declares the CreatureQueue class 
				which provides for doubly linked 
				circular structure that serves as the bases
				for a "queue" of Creature pointers.
***********************************************************/

#ifndef CreatureQueue_hpp
#define CreatureQueue_hpp

#include <iostream>
#include <typeinfo>
#include "Creature.hpp"
using std::cout;
using std::endl;

class CreatureQueue
{
private:
	struct QueueNode
	{
		Creature* creature;
		QueueNode* next;
		QueueNode* previous;
		QueueNode(string sName, int cType,
			QueueNode* next1 = nullptr, 
			QueueNode* previous1 = nullptr);
		QueueNode(Creature* loser,
			QueueNode* next1 = nullptr, 
			QueueNode* previous1 = nullptr);	
	};
	QueueNode* front;
	QueueNode* rear;

public:
	CreatureQueue();
	~CreatureQueue();
	void addBack
		(string sName, int cType, bool isP1LineUp);
	Creature* getFront();
	Creature* removeFront();
	void printQueue();
	void cycleFrontToBack();
	bool isEmpty() const;
	class EmptyQueue{};
};

#endif /* CreatureQueue_hpp */
