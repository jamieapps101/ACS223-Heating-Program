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
		counter++;
		std::cout << std::endl;
        }
	
	// ~read data from file
	// Close file stream
	inputFile.close();
	// ~Close file stream
	return 0;
}
