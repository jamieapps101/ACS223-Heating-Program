#include "room.h"
#include <string>

room::room()
{
	typeIndex = 0;
	type = "";
	floorSpace = 0;
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

