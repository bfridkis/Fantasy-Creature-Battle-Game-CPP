/*************************************************************
** Program name: CreatureQueue.cpp
** Author: Ben Fridkis
** Date: 5/16/2017
** Description: CreatureQueue.cpp source file. Provides the 
**				member function definitions for the 
**				CreatureQueue class, which provides a doubly-
**				linked circular structure to implement a
**				queue of Creature pointers (Project 4).
*************************************************************/

#include "CreatureQueue.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

/*********************************************
			   	Constructor
 Instatitates a Queue object with front and
 rear pointer-to-QueueNode members set as
 nullptr.
**********************************************/
CreatureQueue::CreatureQueue()
{
	front = nullptr;
	rear = nullptr;
}
/***************************************************
	   Constructor (Nested QueueNode Struct)
  Instatitates a Queue object with front and rear 
  pointer-to-QueueNode members set as nullptr.
  Creates new creature with sName (spcific name)
  and cType (parameters).
****************************************************/
CreatureQueue::QueueNode::QueueNode(string sName, 
	int cType, QueueNode* next1, QueueNode* previous1)
{
	if (cType == 1)
	{
		creature = new Vampire(sName);
	}
	else if (cType == 2)
	{
		creature = new Barbarian(sName);
	}
	else if (cType == 3)
	{
		creature = new BlueMen(sName);
	}
	else if (cType == 4)
	{
		creature = new Medusa(sName);
	}
	else if (cType == 5)
	{
		creature = new HarryPotter(sName);
	}
	next = next1;
	previous = previous1;
}
/***************************************************
	   Constructor (Nested QueueNode Struct)
  Overloaded constructor using a Creature* instead
  of specific name and creature type parameters to 
  create a QueueNode struct object.
****************************************************/
CreatureQueue::QueueNode::QueueNode(Creature* loser,
	QueueNode* next1, QueueNode* previous1)
{
	creature = loser;
	next = next1;
	previous = previous1;
}
/*******************************************
    		    Destructor
  Queue object destructor. Deallocates all
  memory assigned to QueueNodes.
*********************************************/
CreatureQueue::~CreatureQueue()
{
	//Deletes all nodes up to last node.
	//(When only one node remains, front
	//is equivalent to back because structure
	//is circular.)
	QueueNode* nodeToDelete = front;
	while (front != rear)
	{
		front = front->previous;
		delete nodeToDelete->creature;
		delete nodeToDelete;
		nodeToDelete = front;
	}
	//Deallocates memory for last remaining
	//node.
	if(front != nullptr)
	{
		delete front->creature;
		delete front;
	}
}
/*******************************************
				 addBack
 Function to add a node to the rear of the
 queue. If the queue is empty, creates
 a new QueueNode and assigns both front 
 and back pointers to this new node. If 
 there is only one node in the Queue, adds
 a second node and assigns it's next 
 and previous pointers the value of front
 and assigns front's next and previous 
 pointers the value of (the newly created)
 rear. Else, creates a temp QueueNode, 
 assigns it the value of rear, reassigns 
 rear to a new QueueNode, and passes the 
 new node the value of temp for it's next 
 node pointer and the value of front for 
 its previous node pointer. Front's next
 pointer is reassigned the value of the 
 newly created rear. Passes sName (specific
 name) and cType (creature type) to the 
 node constructor.
*******************************************/
void CreatureQueue::addBack(string sName, 
	int cType, bool isP1LineUp)
{
	if (isP1LineUp)
	{
		if (front == nullptr && rear == nullptr)
		{
			rear = new QueueNode(sName, cType);
			front = rear;
			front->next = rear;
			front->previous = rear;
			rear->next = front;
			rear->previous = front;
		}
		else if (front == rear)
		{
			rear = new QueueNode(sName, cType, 
				front, front);
			front->next = rear;
			front->previous = rear;
		}
		else
		{
			QueueNode* temp = rear;
			rear = new QueueNode(sName, cType,
				temp, front);
			front->next = rear;
			temp->previous = rear;
		}

		if (cType == 1)
		{	
			cout << "\nVampire " << sName 
				 << " added to P1 lineup." 
				 << endl << endl;
		}
		else if (cType == 2)
		{	
			cout << "\nBarbarian " << sName 
				 << " added to P1 lineup." 
				 << endl << endl;
		}
		else if (cType == 3)
		{	
			cout << "\nBlueMen " << sName 
				 << " added to P1 lineup." 
				 << endl << endl;
		}
		else if (cType == 4)
		{	
			cout << "\nMedusa " << sName 
				 << " added to P1 lineup." 
				 << endl << endl;
		}
		else if (cType == 5)
		{	
			cout << "\nHarry Potter " << sName 
				 << " added to P1 lineup." 
				 << endl << endl;
		}
	}
	else if (!isP1LineUp)
	{
		if (front == nullptr && rear == nullptr)
		{
			rear = new QueueNode(sName, cType);
			front = rear;
			front->next = rear;
			front->previous = rear;
			rear->next = front;
			rear->previous = front;
		}
		else if (front == rear)
		{
			rear = new QueueNode(sName, cType, 
				front, front);
			front->next = rear;
			front->previous = rear;
		}
		else
		{
			QueueNode* temp = rear;
			rear = new QueueNode(sName, cType,
				temp, front);
			front->next = rear;
			temp->previous = rear;
		}

		if (cType == 1)
		{	
			cout << "\nVampire " << sName 
				 << " added to P2 lineup." 
				 << endl << endl;
		}
		else if (cType == 2)
		{	
			cout << "\nBarbarian " << sName 
				 << " added to P2 lineup." 
				 << endl << endl;
		}
		else if (cType == 3)
		{	
			cout << "\nBlueMen " << sName 
				 << " added to P2 lineup." 
				 << endl << endl;
		}
		else if (cType == 4)
		{	
			cout << "\nMedusa " << sName 
				 << " added to P2 lineup." 
				 << endl << endl;
		}
		else if (cType == 5)
		{	
			cout << "\nHarry Potter " << sName 
				 << " added to P2 lineup." 
				 << endl << endl;
		}
	}
}
/****************************************
		        getFront
 Function to return the value at the 
 front of the queue. If list is empty,
 an exception is thrown and a message is 
 printed from main.
*****************************************/
Creature* CreatureQueue::getFront()
{
	return front->creature;	
}
/******************************************
    		    removeFront 
  Removes the node at the front of the 
  queue. If queue is empty (designated by
  the fact that front == nullptr), print
  error message. If there is only one node
  remaining, first determine and creature
  type and create a new creature that will
  be transferred via the Creature* loser to
  the user stack, then delete front and set
  front and rear to nullptr. If more than
  one node remains, determine and creature
  type and create a new creature that will
  be transferred via the Creature* loser to
  the user stack, delete front, then
  reassign front to temp's previous pionter
  and set (the new) front's next pointer
  to rear.
*********************************************/
Creature* CreatureQueue::removeFront()
{
	if (front == nullptr)
	{
		throw EmptyQueue();	
	}
	else if (front == rear)
	{
		Creature* loser;
		string loserName = front->creature->
			getSName();	
		if (typeid(*front->creature) ==
			typeid(Vampire))
		{
			loser = new Vampire(loserName, 0);	
		}
		else if (typeid(*front->creature) ==
			typeid(Barbarian))
		{
			loser = new Barbarian(loserName, 0);
		}
		else if (typeid(*front->creature) ==
			typeid(BlueMen))
		{
			loser = new BlueMen(loserName, 0);
		}
		else if (typeid(*front->creature) ==
			typeid(Medusa))
		{
			loser = new Medusa(loserName, 0);
		}
		else if (typeid(*front->creature) ==
			typeid(HarryPotter))
		{
			loser = new HarryPotter(loserName, 0);
		}
		
		delete front->creature;
		delete front;
		front = rear = nullptr;
		
		return loser;
	}
	else
	{
		Creature* loser;
		string loserName = front->creature->
			getSName();
		if (typeid(*front->creature) ==
			typeid(Vampire))
		{
			loser = new Vampire(loserName, 0);	
		}
		else if (typeid(*front->creature) ==
			typeid(Barbarian))
		{
			loser = new Barbarian(loserName, 0);	
		}
		else if (typeid(*front->creature) ==
			typeid(BlueMen))
		{
			loser = new BlueMen(loserName, 0);	
		}
		else if (typeid(*front->creature) ==
			typeid(Medusa))
		{
			loser = new Medusa(loserName, 0); 	
		}
		else if (typeid(*front->creature) ==
			typeid(HarryPotter))
		{
			loser = new HarryPotter(loserName, 0);	
		}
		
		QueueNode* temp = front->previous;
		delete front->creature;
		delete front;
		front = temp;
		front->next = rear;
		rear->previous = front;
		//This next statement is only needed if the
		//2nd to last node is being removed.
		if(front == rear){rear->next = front;}
		return loser;
	}
}
/*********************************************
    		    printQueue
  Prints queue contents. Prints rear to front.
**********************************************/
void CreatureQueue::printQueue()
{
	//If there are no nodes in the queue,
	//print message accordingly.
	if (front == nullptr)
	{
		throw EmptyQueue();
	}
	else 
	{
		QueueNode* nodeToPrint = rear;
		while (nodeToPrint != front)
		{
			cout << nodeToPrint->creature->getSName()
				 << " || " << "Remaining Strength Points: "
				 << nodeToPrint->creature->getStrengthPoints()
				 << endl;
			nodeToPrint = nodeToPrint->next;
		}
		cout << front->creature->getSName()
				 << " || " << "Remaining Strength Points: "
				 << nodeToPrint->creature->getStrengthPoints()
				 << endl << endl;
	}
	
}
/*********************************************
    		  cycleFrontToBack
  Cycles the front node to the rear as long
  as at least two nodes remain in the queue.
**********************************************/
void CreatureQueue::cycleFrontToBack()
{
	if (front == nullptr)
	{
		throw EmptyQueue();
	}
	else if (front != rear)
	{
		QueueNode* oldFront = front;
		QueueNode* oldRear = rear;
		front = front->previous;
		rear = oldFront;
		front->next = rear;
		oldRear->previous = rear; 
		rear->next = oldRear;
		rear->previous = front;
	}
}
/*********************************************
					isEmpty
 Returns boolean true if the queue is empty.
 Otherwise, returns false.
 *********************************************/
 bool CreatureQueue::isEmpty() const
 {
	 return front == nullptr;
 }