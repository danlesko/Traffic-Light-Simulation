//Daniel Lesko
//CMSY 341 - Section 5
//September 27, 2014

#ifndef RESULTVEHICLE_H
#define RESULTVEHICLE_H
#include <string>
#include <iostream>

using namespace std;

class ResultVehicle
{
	private:
		char type;
		int timeEntered;
		int timeExited;
		int timeWaited;


	public:
		
		ResultVehicle(char,int,int);

		void setType(char);
		void setTimeEntered(int);
		void setTimeExited(int);
		void setTimeWaited(int,int);

		char getType();
		int getTimeEntered();
		int getTimeExited();
		int getTimeWaited();


};
#endif