//Daniel Lesko
//CMSY 341 - Section 5
//September 27, 2014

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
#include "ResultVehicle.h"

using namespace std;

class Linked_List
{
	private:

		//linked list 
		struct ListNode
		{
			ResultVehicle * vehicle;
			struct ListNode *next;
		};

		ListNode * head;
		ListNode * tail;

		//result variables
		int totalVehicles;
		int totalCars;
		int totalTrucks;
		int totalWaitTime;
		float averageWait;

	
	public:
		//constructor
		Linked_List();

		//destructor
		~Linked_List();

		//linked list operations
		void appendNode(char, int, int);
		void displayList() const;
		void traverseList();
		void printResults();

		//incrementors
		void incrementVehicles();
		void incrementCars();
		void incrementTrucks();
		void incrementWaitTime(int);

		//getters
		int getVehicleTotals();
		int getCarTotals();
		int getTruckTotals();
		int getTotalWaitTime();
		float averageWaitTime();
};
#endif