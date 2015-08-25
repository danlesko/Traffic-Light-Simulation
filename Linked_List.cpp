#include <string>
#include <iostream>
#include <iomanip>
#include "Linked_List.h"

using namespace std;

//constructor definition
Linked_List::Linked_List()
{
	//initializes all incrementors
	totalVehicles = 0;
	totalCars = 0;
	totalTrucks = 0;
	totalWaitTime = 0;
	head = NULL;
}

//destructor definition
Linked_List::~Linked_List()
{
	ListNode *nodePtr; // to traverse list
	ListNode *nextNode; // to point to the next node

	//position nodePtr at head of list
	nodePtr = head;

	while(nodePtr != NULL) //while nodePtr is not at end of the list...
	{
		//save ptr to the next node
		nextNode = nodePtr->next;

		//delete the current node and the dynamically stored resultVehicle
		delete nodePtr->vehicle;
		nodePtr->vehicle = NULL;
		delete nodePtr;
		nodePtr = NULL;

		//position nodePtr at the next node
		nodePtr = nextNode;
	}
}

//add node to list
void Linked_List::appendNode(char kind, int in, int out)
{
	ListNode * newNode; // to traverse list
	ListNode * nodePtr; // to point to next node

	newNode = new ListNode; // creates new node
	newNode->vehicle = new ResultVehicle(kind, in, out); // creates resultVehicle object
	newNode->next = NULL; 

	//If no new nodes in list make newNode the first
	if(!head)
	{
		head = newNode;
	}

	else
	{
		//initialize nodePtr to head of list
		nodePtr = head;

		//find last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
		tail = newNode;
	}
}

//not used during actual simulation but was helpful for testing to see if list was linked
void Linked_List::displayList() const
{
	ListNode * nodePtr; // to traverse list

	nodePtr = head; // initial nodePtr to  head

	while(nodePtr) // while nodePtr points to something display vehicle types
	{
		cout << nodePtr->vehicle->getType() << endl;

		nodePtr = nodePtr->next;
	}
}

//traverses the list and updates each incrementor
void Linked_List::traverseList()
{
	//to move hrough the list
	ListNode * nodePtr;

	//position nodePtr at front of list
	nodePtr = head;

	//while nodePtr points to a node, traverse the list
	//and add up total cars, trucks, and wait times
	while (nodePtr)
	{
		incrementVehicles();//adds 1 vehicle for each node

		if (nodePtr->vehicle->getType() == 'c') // determines vehicle type and increments the correct total
			incrementCars();
		else if (nodePtr->vehicle->getType() == 't')
			incrementTrucks();

		incrementWaitTime(nodePtr->vehicle->getTimeWaited()); // increments total wait time for all vehicles

		nodePtr = nodePtr->next; // points to the next node
	}
}

//increments total vehicles passed
void Linked_List::incrementVehicles()
{
	totalVehicles += 1;
}

//increments total cars passed
void Linked_List::incrementCars()
{
	totalCars += 1;
}

//increments total trucks passed
void Linked_List::incrementTrucks()
{
	totalTrucks += 1;
}

//increments total wait time 
void Linked_List::incrementWaitTime(int wait)
{
	totalWaitTime = totalWaitTime + wait;
}

//returns total vehicles passed
int Linked_List::getVehicleTotals()
{
	return totalVehicles;
}

//returns total cars passed
int Linked_List::getCarTotals()
{
	return totalCars;
}

//returns total trucks passed
int Linked_List::getTruckTotals()
{
	return totalTrucks;
}

//returns total wait time
int Linked_List::getTotalWaitTime()
{
	return totalWaitTime;
}

//calculates the average wait time for the intersection
float Linked_List::averageWaitTime()
{
	averageWait = (static_cast<float>(totalWaitTime) / static_cast<float>(totalVehicles));
	return averageWait;
}

//prints the results of the simulation to the screen
void Linked_List::printResults()
{
	cout << "The final results are:" << endl;
	cout << "The number of vehicles that passed through the intersection is: " << getVehicleTotals() << endl;
	cout << "The number of cars that passed through the intersection is: " << getCarTotals() << endl;
	cout << "The number of trucks that passed through the intersection is: " << getTruckTotals() << endl;
	cout << "The average wait time for this intersection is: " << setprecision(8) <<  showpoint << averageWaitTime() << endl;
}