#include <iostream>
#include <string>
#include <fstream>
// Main of heating calculator program
// Written by Jamie Apps
// 7/11/17

struct officeStructure
{
	int index;
	std::string name;
	int floorSpace;
};

void getInputData( struct * officeStructure input, std::string inputLine);

int main()
{
	bool validInputFileName = false;
	std::string inputFileName;
	std::ifstream inputFile;
	// Get valid input file
	std::cout << "Please input name of file:" << std::endl;
	while(validInputFileName == false)
	{
		std::cin >> inputFileName;
		inputFile.open(inputFileName.c_str());
		if(!inputFile)
		{
			std::cout << "Unable to open file: " << inputFileName.c_str() << std::endl;
			std::cout << "Please try again: " << std::endl;
		}
		else
		{
			std::cout << "Successfully opened file" << std::endl;
			validInputFileName = true;
		}
	}
	// ~Get valid input filename
	// Read data from file
	std::cout << "Reading data" << std::endl;

        std::string inputString[15];
	std::string tempString;
	int counter = 0;
	while(!inputFile.eof())
        {
	        getline(inputFile,inputString[counter]);
		std::cout << inputString[counter];
		std::cout << (inputString[counter])[0] << std::endl;
		
		counter++;
		std::cout << std::endl;
        }
	// ~read data from file
	// Close file stream 
	inputFile.close();
	// ~Close file stream
	return 0;
}

void getInputData( struct * officeStructure input, std::string inputLine)
{
	int inputIndex;
	std:string inputName;
	int inputFloorSpace;
	int spaceIndex[5];
	int spaceCounter = 0;
	bool previousSpace = false;
	bool currentSpace = false;
	char currentChar;
	int currentIndex = 0;
	while((currentChar = inputString[currentIndex]) != EOL)
	{
		if(currentChar == ' ')
		{
			currentSpace = true;
		}

		if(currentSpace != previousSpace) // ie  start/end of data
		{
			spaceIndex[spaceCounter] = currentIndex;
			spaceCounter++;
		}

		if(currentSpace == true)
		{
			currentSpace = false;
			previousSpace = true;
		}
		else
		{
			previousSpace = false;
		}
		currentIndex++;
	}
	spaceIndex[4] = currentIndex-1;
	int sizeStore[3] = {spaceIndex[0],spaceIndex[2] - spaceIndex[1],spaceIndex[4] - spaceIndex[3]};
	int indexStore[3] = {0,spaceIndex[1],spaceIndex[3]};
	char indexChars[spaceIndex[0]];
	char nameChars[spaceIndex[2] - spaceIndex[1]];
	char floorSpaceChars[spaceIndex[4] - spaceIndex[3]];
	input-->index = inputIndex;
	input-->name = inputName;
	input-->floorSpace = inputFloorSpace;
}
