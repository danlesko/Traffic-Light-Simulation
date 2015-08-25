//Daniel Lesko
//CMSY 341 - Section 5
//September 27, 2014

#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "TrafficSim.h"

using namespace std;

//constructor that accepts a filename
TrafficSim::TrafficSim(string filename)
{
	//initializes queues
	eastbound = new queue <Vehicle>;
	westbound = new queue <Vehicle>;
	northbound = new queue <Vehicle>;
	southbound = new queue <Vehicle>;

	//calls readFromFile and updates flowRates
	isFile = readFromFile(filename);

	//adds 2 cars to each queue before sim starts
	int initialTime = 0;
	eastbound->push(Vehicle('c',initialTime));
	eastbound->push(Vehicle('c',initialTime));
	westbound->push(Vehicle('c',initialTime));
	westbound->push(Vehicle('c',initialTime));
	northbound->push(Vehicle('c',initialTime));
	northbound->push(Vehicle('c',initialTime));
	southbound->push(Vehicle('c',initialTime));
	southbound->push(Vehicle('c',initialTime));

	printBoard(initialTime);

}

//default constructor
TrafficSim::TrafficSim()
{
	//prints error message to the screen and exits program
	cout << "No input file found!!!! ABORTING....." << endl;
	isFile = false;
	//exit(1);
}

TrafficSim::~TrafficSim()
{
	//deletes queues at end of program
	delete eastbound;
	delete westbound;
	delete northbound;
	delete southbound;
	eastbound = NULL;
	westbound = NULL;
	northbound = NULL;
	southbound = NULL;
}

//opens file
bool TrafficSim::readFromFile(string filename)
{
	bool openFile = true;

	//opens file for read in
	fstream infile(filename.c_str(), ios::in);
	if(infile.fail()) // if file doesn't open return print error message and exit program
	{
		cout << "File was not successfully opened." << endl;
		openFile = false;
		return openFile;
	}

	string getDirection;
	int getCars;
	int getTrucks;

	//read from file and assign flowRates to appropriate car and truck queues
	do
	{
		infile >> getDirection;
		infile >> getCars;
		infile >> getTrucks;

		if(getDirection == "//")
		{
			infile.close();
			return openFile;
		}

		if (getDirection == "N:")
		{
			flowRate.setNorthCars(getCars);
			flowRate.setNorthTrucks(getTrucks);
		}
		else if (getDirection == "S:")
		{
			flowRate.setSouthCars(getCars);
			flowRate.setSouthTrucks(getTrucks);
		}
		else if (getDirection == "E:")
		{
			flowRate.setEastCars(getCars);
			flowRate.setEastTrucks(getTrucks);
		}
		else if (getDirection == "W:")
		{
			flowRate.setWestCars(getCars);
			flowRate.setWestTrucks(getTrucks);
		}

	} while (!infile.eof());

	infile.close();
	return openFile;

}

//adds vehicle to correct directional queue
bool TrafficSim::addVehicle(char direction, Vehicle x)
{
	bool vehicleAdd = true;
	return vehicleAdd;
}

//prints the board each time
void TrafficSim::printBoard(int time)
{
	int clockTime = time;
	//southbound print out
	cout << setw(5) << "SB";
	if (southbound->size() > 5)
	{
		cout << setw(2) << "x";
		cout << setw(2) << southbound->size() << endl;
	}
	else
		cout << setw(5) << southbound->size() << endl;
	if (southbound->size() > 4)
		cout << setw(7) << "x" << endl;
	else
		cout << endl;
	if (southbound->size() > 3)
		cout << setw(7) << "x" << endl;
	else
		cout << endl;
	if (southbound->size() > 2)
		cout << setw(7) << "x" << endl;
	else
		cout << endl;
	cout << "EB";
	if (southbound->size() > 1)
		cout << setw(5) << "x" << endl;
	else 
		cout << endl;
	cout << " " << eastbound->size();
	if((eastbound->size() > 0) && (eastbound->size() < 10))
	{
		if (!southbound->empty())
		{
			cout << setw(5) << southbound->front();
		}
	}
	else if ((eastbound->size()) >= 10)
	{
		if (!southbound->empty())
		{
			cout << setw(4) << southbound->front();
		}
	}
	else if ((eastbound->size()) == 0)
	{
		if (!southbound->empty())
		{
			cout << setw(5) << southbound->front();
		}
	}
	cout << endl;

	//eastbound print out
	if (eastbound->size() >= 6)
		cout << "xxxxx" << eastbound->front() << " ";
	if (eastbound->size() == 5)
		cout << setw(5) << "xxxx" << eastbound->front() << " ";
	if (eastbound->size() == 4)
		cout << setw(5) << "xxx" << eastbound->front() << " ";
	if (eastbound->size() == 3)
		cout << setw(5) << "xx" << eastbound->front() << " ";
	if (eastbound->size() == 2)
		cout << setw(5) << "x" << eastbound->front() << " ";
	if (eastbound->size() == 1) 
		cout << setw(6) << eastbound->front() << " ";
	if (eastbound->size() ==0)
		cout << setw(7) << " ";

	//westbound print out
	if (westbound->size() >=6)
		cout << westbound->front() << "xxxxx" << endl;
	if (westbound->size() == 5)
		cout << westbound->front() << "xxxx" << endl;
	if (westbound->size() == 4)
		cout << westbound->front() << "xxx" << endl;
	if (westbound->size() == 3)
		cout << westbound->front() << "xx" << endl;
	if (westbound->size() == 2)
		cout << westbound->front() << "x" << endl;
	if (westbound->size() == 1)
		cout << westbound->front() << endl;
	if (westbound->size() == 0)
		cout << " " << endl;


	//northbound print out
	if (northbound->size() > 0)
		cout << setw(7) << northbound->front() << endl;
	else
		cout << endl;

	if (northbound->size() > 1)
		cout << setw(7) << "x" << setw(6) << "WB" << endl;
	else
		cout << "           " << "WB" << endl;

	if (northbound->size() > 2)
		cout << setw(7) << "x" << "     " << westbound->size() << endl;
	else
		cout << "            " << westbound->size() << endl;

	if (northbound->size() > 3)
		cout << setw(7) << "x" << endl;
	else
		cout << endl;
	if (northbound->size() > 4)
		cout << setw(7) << "x" << endl;
	else
		cout << endl;
	if (northbound->size() > 5)
	{
		cout << setw(5) << "NB";
		cout << setw(2) << "x";
		cout << setw(3) << northbound->size() << endl;
	}
	else
	{
		cout << setw(5) << "NB" << setw(5) << northbound->size() << endl;
	}

	cout << "at clock: " << setw(3) << clockTime << endl;
	cout << "--------------------------------------" << endl << endl;
}

//runs the program
void TrafficSim::DoRun()
{
	//if isFile is true, run sim, otherwise do nothing
	if (isFile)
	{

	//initialize timer variables
	int runTime = 1;
	int oneMin = 60;
	int northSouthTimeGreen = 0;
	int eastWestTimeGreen = 0;

	//bool traffic variables and our green/red variable
	bool eastWestTraffic = true;
	bool northSouthTraffic = true;
	bool northSouthGreen = true; //north south is true == green, then east west is false == red, and vice versa

	//when cars get added
	int carsAddNorth = oneMin / flowRate.getNorthCars();
	int carsAddSouth = oneMin / flowRate.getSouthCars();
	int carsAddEast = oneMin / flowRate.getEastCars();
	int carsAddWest = oneMin / flowRate.getWestCars();
	int trucksAddNorth = oneMin / flowRate.getNorthTrucks();
	int trucksAddSouth = oneMin / flowRate.getSouthTrucks();
	int trucksAddEast = oneMin / flowRate.getEastTrucks();
	int trucksAddWest = oneMin / flowRate.getWestTrucks();

	//bool variables to determine if trucks have waited 2 seconds to pass
	bool northTruckWait = false;
	bool southTruckWait = false;
	bool eastTruckWait = false;
	bool westTruckWait = false;

	//main program algorithm
	do
	{
		//check to see if traffic is at E/W intersection
		if ((!eastbound->empty()) || (!westbound->empty()))
			eastWestTraffic = true;
		else
			eastWestTraffic = false;

		//checks to see if traffic is at N/S intersection
		if ((!southbound->empty()) || (!northbound->empty()))
			northSouthTraffic = true;
		else
			northSouthTraffic = false;

		//
		//TRAFFIC LIGHT ALGORITHM
		//
		
		//if we have east/west traffic
		if (eastWestTraffic)
		{
			//if beginning of program north/south light is green
			if (runTime == 1)
			{
				northSouthGreen = true;
				northSouthTimeGreen = 0;
				northSouthTimeGreen++;
			}
			//else if north south is green and has ben green for 30 seconds set to red and let east west be green
			else if (northSouthGreen && northSouthTimeGreen == 30)
			{
				northSouthGreen = false;
				eastWestTimeGreen = 0;
				northSouthTimeGreen = 0;
				eastWestTimeGreen++;
			}
			//else if it is green has been less than 30 seconds keep incrementing counter
			else if (northSouthGreen && northSouthTimeGreen < 30)
			{
				northSouthTimeGreen++;
			}
			//else if eastwest is green and has been for 30 seconds set to red and let north south be green
			else if (!northSouthGreen && eastWestTimeGreen == 30)
			{
				northSouthGreen = true;
				northSouthTimeGreen = 0;
				eastWestTimeGreen = 0;
				northSouthTimeGreen++;
			}
			//else if eastwest is green and has been for less than 10 seconds keep incrementing counter
			else if (!northSouthGreen && eastWestTimeGreen < 10)
			{
				eastWestTimeGreen++;
			}
		}

		//else if there is no east west traffic
		else if (!eastWestTraffic)
		{
			//if north south is green keep incrementing
			if (northSouthGreen)
			{
				northSouthTimeGreen++;
			}
			//else if east west is green and it has been for 10 seconds change to red and let north south be green
			else if (!northSouthGreen && eastWestTimeGreen == 10)
			{
				northSouthGreen = true;
				northSouthTimeGreen = 0;
				eastWestTimeGreen = 0;
				northSouthTimeGreen++;
			}
			//else if east west is green and it has been less than 10 seconds keep incrementing counter
			else if (!northSouthGreen && (eastWestTimeGreen < 10))
			{
				eastWestTimeGreen++;
			}
		}

		//
		//MOVEMENT OF VEHICLES ALGORITHM
		//
			//if N/S green is true - E/W is red
			if(northSouthGreen)
			{
				//check to see if queue is empty
				if (!(northbound->empty()))
				{
					//if car add to linked list and pop from queue
					if (northbound->front().getType() == 'c')
					{
						list.appendNode(northbound->front().getType(),northbound->front().getTimeEntered(),runTime);
						northbound->pop();
					}
					//if truck wait one interation and then and to linked list and pop
					else if ((northbound->front().getType() == 't'))
					{
						//if we have waited we can remove from list
						if (northTruckWait)
						{
							list.appendNode(northbound->front().getType(),northbound->front().getTimeEntered(),runTime);
							northbound->pop();
							northTruckWait = false;
						}
						//otherwise we we set wait to true and truck will pop next iteration
						else
						{
							northTruckWait = true;
						}
					}
				}

				//check to see if queue is empty
				if (!(southbound->empty()))
				{
					//if car add to linked list and pop from queue
					if (southbound->front().getType() == 'c')
					{
						list.appendNode(southbound->front().getType(),southbound->front().getTimeEntered(),runTime);
						southbound->pop();
					}
					//if truck wait one interation and then and to linked list and pop
					else if ((southbound->front().getType() == 't'))
					{
						//if we have waited we can remove from list
						if (southTruckWait)
						{
							list.appendNode(southbound->front().getType(),southbound->front().getTimeEntered(),runTime);
							southbound->pop();
							southTruckWait = false;
						}
						//otherwise we we set wait to true and truck will pop next iteration
						else
						{
							southTruckWait = true;
						}
					}
				}
				// we set these to false so that way if a light has changed to red and a truck is waiting
				// it must wait again when its light turns green
				eastTruckWait = false;
				westTruckWait = false;
			}

			//if N/S green is false , E/W is green
			if(!northSouthGreen)
			{
				//check to see if queue is empty
				if (!(eastbound->empty()))
				{
					//if car add to linked list and pop from queue
					if (eastbound->front().getType() == 'c')
					{
						list.appendNode(eastbound->front().getType(),eastbound->front().getTimeEntered(),runTime);
						eastbound->pop();
					}
					//if truck wait one interation and then and to linked list and pop
					else if ((eastbound->front().getType() == 't'))
					{
						//if we have waited we can remove from list
						if (eastTruckWait)
						{
							list.appendNode(eastbound->front().getType(),eastbound->front().getTimeEntered(),runTime);
							eastbound->pop();
							eastTruckWait = false;
						}
						//otherwise we we set wait to true and truck will pop next iteration
						else
						{
							eastTruckWait = true;
						}
					}
				}
				//check to see if queue is empty
				if (!(westbound->empty()))
				{
					//if car add to linked list and pop from queue
					if (westbound->front().getType() == 'c')
					{
						list.appendNode(westbound->front().getType(),westbound->front().getTimeEntered(),runTime);
						westbound->pop();
					}
					//if truck wait one interation and then and to linked list and pop
					else if ((westbound->front().getType() == 't'))
					{
							//if we have waited we can remove from list
							if (westTruckWait)
							{
								list.appendNode(westbound->front().getType(),westbound->front().getTimeEntered(),runTime);
								westbound->pop();
								westTruckWait = false;
							}
							//otherwise we we set wait to true and truck will pop next iteration
							else
							{
								westTruckWait = true;
							}
						
					}
				}
				// we set these to false so that way if a light has changed to red and a truck is waiting
				// it must wait again when its light turns green
				northTruckWait = false;
				southTruckWait = false;
			}

		//queues
		//vehicles added depending on flow rate
		if ((runTime % carsAddNorth) == 0)
			northbound->push(Vehicle('c',runTime));

		if ((runTime % carsAddSouth) == 0)
			southbound->push(Vehicle('c',runTime));

		if ((runTime % carsAddEast) == 0)
			eastbound->push(Vehicle('c',runTime));

		if ((runTime % carsAddWest) == 0)
			westbound->push(Vehicle('c',runTime));

		if ((runTime % trucksAddNorth) == 0)
			northbound->push(Vehicle('t',runTime));

		if ((runTime % trucksAddSouth) == 0)
			southbound->push(Vehicle('t',runTime));

		if ((runTime % trucksAddEast) == 0)
			eastbound->push(Vehicle('t',runTime));

		if ((runTime % trucksAddWest) == 0)
			westbound->push(Vehicle('t',runTime));

	//prints board at end of each interation
	printBoard(runTime);
	runTime++;	
	} while (runTime < 121);

	//calls traverse list
	list.traverseList();
	//calls printresults
	list.printResults();

	}
}