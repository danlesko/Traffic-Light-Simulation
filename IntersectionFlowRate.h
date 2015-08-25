//Daniel Lesko
//CMSY 341 - Section 5
//September 27, 2014

#ifndef INTERSECTIONFLOWRATE_H
#define INTERSECTIONFLOWRATE_H
#include <string>
#include <iostream>

using namespace std;

class IntersectionFlowRate
{
	private:
		//flowRate member variables
		int eastFlowRateCars;
		int westFlowRateCars;
		int northFlowRateCars;
		int southFlowRateCars;
		int eastFlowRateTrucks;
		int westFlowRateTrucks;
		int northFlowRateTrucks;
		int southFlowRateTrucks;

	public:
		//mutator functions
		void setEastCars(int);
		void setWestCars(int);
		void setNorthCars(int);
		void setSouthCars(int);
		void setEastTrucks(int);
		void setWestTrucks(int);
		void setNorthTrucks(int);
		void setSouthTrucks(int);

		//accessor functions
		int getEastCars();
		int getWestCars();
		int getNorthCars();
		int getSouthCars();
		int getEastTrucks();
		int getWestTrucks();
		int getNorthTrucks();
		int getSouthTrucks();


};
#endif