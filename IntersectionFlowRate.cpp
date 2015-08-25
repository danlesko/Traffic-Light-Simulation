#include <string>
#include <iostream>
#include "IntersectionFlowRate.h"

using namespace std;

//setter defintions
void IntersectionFlowRate::setEastCars(int rate)
{
	eastFlowRateCars = rate;
}

void IntersectionFlowRate::setWestCars(int rate)
{
	westFlowRateCars = rate;
}

void IntersectionFlowRate::setNorthCars(int rate)
{
	northFlowRateCars = rate;
}

void IntersectionFlowRate::setSouthCars(int rate)
{
	southFlowRateCars = rate;
}

void IntersectionFlowRate::setEastTrucks(int rate)
{
	eastFlowRateTrucks = rate;
}

void IntersectionFlowRate::setWestTrucks(int rate)
{
	westFlowRateTrucks = rate;
}

void IntersectionFlowRate::setNorthTrucks(int rate)
{
	northFlowRateTrucks = rate;
}

void IntersectionFlowRate::setSouthTrucks(int rate)
{
	southFlowRateTrucks = rate;
}


//getter definitions
int IntersectionFlowRate::getEastCars()
{
	return eastFlowRateCars;
}

int IntersectionFlowRate::getWestCars()
{
	return westFlowRateCars;
}

int IntersectionFlowRate::getNorthCars()
{
	return northFlowRateCars;
}

int IntersectionFlowRate::getSouthCars()
{
	return southFlowRateCars;
}

int IntersectionFlowRate::getEastTrucks()
{
	return eastFlowRateTrucks;
}

int IntersectionFlowRate::getWestTrucks()
{
	return westFlowRateTrucks;
}

int IntersectionFlowRate::getNorthTrucks()
{
	return northFlowRateTrucks;
}

int IntersectionFlowRate::getSouthTrucks()
{
	return southFlowRateTrucks;
}















