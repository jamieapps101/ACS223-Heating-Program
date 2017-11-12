#include "room.h"
#include <string>

room::room()
{
	typeIndex = 0;
	type = "";
	floorSpace = 0;
	hoursPerDayHeated = 0.0;D
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

void sethoursPerDayHeated(float &input)
{
	hoursPerDayHeated = input;
}

void setDaysPerYearHeated(float &input);
{
	daysPerYearHeated = input;
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

float getHoursPerDayHeated()
{
	return HoursPerDayHeated;
}

float getDaysPerYearHeated()
{
	return daysPerYearHeated;
}
