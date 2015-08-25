#include <string>
#include <iostream>
#include "ResultVehicle.h"

using namespace std;

ResultVehicle::ResultVehicle(char kind, int in, int out)
{
	type = kind;
	timeEntered = in;
	timeExited = out;
	setTimeWaited(in,out);
}

void ResultVehicle::setTimeWaited(int in, int out)
{
	timeWaited = out - in;
}

void ResultVehicle::setTimeEntered(int in)
{
	timeEntered = in;
}

void ResultVehicle::setTimeExited(int out)
{
	timeExited = out;
}

void ResultVehicle::setType(char kind)
{
	type = kind;
}

char ResultVehicle::getType()
{
	return type;
}

int ResultVehicle::getTimeEntered()
{
	return timeEntered;
}

int ResultVehicle::getTimeExited()
{
	return timeExited;
}

int ResultVehicle::getTimeWaited()
{
	return timeWaited;
}