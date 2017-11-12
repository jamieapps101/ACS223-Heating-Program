#include "room.h"
#include <string>

room::room()
{
	typeIndex = 0;
	type = "";
	floorSpace = 0;
	hoursPerDayHeated = 0.0;
}

void room::setTypeIndex(int &input)
{
	typeIndex = input;
}

void room::setType(std::string &input)
{
	type = input;
}

void room::setFloorSpace(int &input)
{
	floorSpace = input;
}

void room::setHoursPerDayHeated(float &input)
{
	hoursPerDayHeated = input;
}

void room::setDaysPerYearHeated(float &input)
{
	daysPerYearHeated = input;
}

void room::setHeatingTemp(float &input)
{
	heatingTemp = input;
}

int room::getTypeIndex()
{
        return typeIndex;
}

std::string room::getType()
{
        return type;
}

int room::getFloorSpace()
{
        return floorSpace;
}

float room::getHoursPerDayHeated()
{
	return hoursPerDayHeated;
}

float room::getDaysPerYearHeated()
{
	return daysPerYearHeated;
}

float room::getHeatingTemp()
{
	return heatingTemp;
}
