#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H
#include "Vehicle.h"
#include "IntersectionFlowRate.h"
#include "Linked_List.h"
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdlib>

using namespace std;

class TrafficSim
{
	
	private:

		bool isFile;

		queue <Vehicle> * eastbound;
		queue <Vehicle> * westbound;
		queue <Vehicle> * northbound;
		queue <Vehicle> * southbound;

		Linked_List list;

		IntersectionFlowRate flowRate;

		bool readFromFile(string filename);

		bool addVehicle(char direction, Vehicle x);

		void printBoard(int);

	public:
		TrafficSim(string);
		TrafficSim();
		~TrafficSim();
		void DoRun();
};

#endif