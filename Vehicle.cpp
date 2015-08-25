#include <string>
#include <iostream>
#include <queue>
#include "Vehicle.h"

using namespace std;

//setters
void Vehicle::setType(char vehicleType)
{
	type = vehicleType;
}

void Vehicle::setTimeEntered(int time)
{
	timeEntered = time;
}

//getters
char Vehicle::getType() const
{
	return type;
}

int Vehicle::getTimeEntered() const
{
	return timeEntered;
}

//constructor definition
Vehicle::Vehicle(char vehicleType, int time)
{
	type = vehicleType;
	timeEntered = time;
}