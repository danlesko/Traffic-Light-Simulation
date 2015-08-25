//Daniel Lesko
//CMSY 341 - Section 5
//September 27, 2014

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
#include <queue>

using namespace std;

class Vehicle
{
	private:
		//member variables
		char type;
		int timeEntered;

	public:
		//setters
		void setType(char);
		void setTimeEntered(int);

		//getters
		char getType() const;
		int getTimeEntered() const;

		//constructor
		Vehicle(char, int);

		//overloaded << to display vehicle type
		friend ostream &operator << (ostream &strm, const Vehicle &obj)
		{
			strm << obj.getType();
			return strm;
		}
};
#endif