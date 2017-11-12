#define activation false

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "room.h"
#include <iomanip>
// Main of heating calculator program
// Written by Jamie Apps
// 7/11/17
//hello
struct officeStructure
{
	int index;
	std::string name;
	int floorSpace;
};

void getInputData( struct officeStructure *input, std::string inputLine);
void getIntInput(int *inputVariable, int min, int max);
void getStringInput(std::string *inputVariable, char type);
void flag(int flagNo);
void getFloatInput(float *inputVariable, float min, float max);


int main()
{
	bool validInputFileName = false;; /////////////////////////////////////This and line below /////////////////////////////////////
	std::string inputFileName = "inputdata.txt";
	std::ifstream inputFile;
	// Get valid input file
	std::cout << "Please input name of file:" << std::endl;
	while(validInputFileName == false)
	{
		//std::cin >> inputFileName; ////////////////////////////////////This one/////////////////////////////////
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
	flag(1);
	struct officeStructure officeOptions[15];
	flag(2);
  std::string tempString;
	flag(3);
	int optionsCounter = 0;
	flag(4);
	while(getline(inputFile,tempString))
        {
		flag(10);
		optionsCounter++;
		flag(11);
	        //getline(inputFile,tempString);
		flag(12);
		std::cout << "tempString " << tempString << std::endl;
		//std::cout << std::endl;
		getInputData( &(officeOptions[optionsCounter-1]), tempString);
		flag(13);
		//optionsCounter++;
        }
	// ~read data from file

	// Close file stream
	inputFile.close();
	// ~Close file stream

	//Ask user to Specify Office
	std::cout << "How many rooms would you like to specfiy?:" << std::endl;
	int rooms;
	getIntInput(&rooms, 1, 20);
	room userOffice[rooms];
	std::cout << "For each of the following rooms, you must specify a type." << std::endl;
	std::cout << "From the input file, you have the following options to choose:" << std::endl;
	for(int a = 0; a < optionsCounter; a++)
	{
		std::cout << std::setw(2) << officeOptions[a].index;
		std::cout << std::setw(20) << officeOptions[a].name;
		std::cout << std::setw(5) << officeOptions[a].floorSpace << std::endl;
	}
	std::cout << "For each of the rooms, please specify a type by typing the index number" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": ";
		int inputValue;
		getIntInput(&inputValue, 1, optionsCounter);
		//getValidUserData(&inputValue, 'n');
		userOffice[a].setTypeIndex(inputValue);
	}
	std::cout << "You have entered rooms of the following types:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		int roomType = userOffice[a].getTypeIndex();
		std::cout << a << ": " << officeOptions[roomType+1].name << std::endl;
	}
	// ~Ask user to specify office
	// Ask user to heating options
	std::cout << "And now for each of these rooms, please specify how many hours per day you" << std::endl;
	std::cout << "would like them to be heated for:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": ";
		float inputValue;
		getFloatInput(inputValue,0,24);
		userOffice[a].setTypeIndex(inputValue);
	}
	std::cout << "And now for each of these rooms, please specify how many days per year you" << std::endl;
	std::cout << "would like them to be heated for:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": ";
		float inputValue;
		getFloatInput(inputValue,0,24);
		userOffice[a].setTypeIndex(inputValue);
	}
	// ~Ask user to heating options
	return 0;
}


void getInputData( struct officeStructure *input, std::string inputLine)
{
	flag(20);
	int inputIndex = 0;
	std::string inputName;
	int inputFloorSpace = 0;

	int spaceIndex[5];
	int spaceCounter = 0;

	bool previousSpace = false;
	bool currentSpace = false;

	char currentChar = false;
	int currentIndex = 0;
	flag(21);
        std::cout << "InputLine " << inputLine << std::endl;
        std::cout << "inputLine.length() " << inputLine.length() << std::endl;

	while(currentIndex < inputLine.length())
	{
		currentChar = inputLine[currentIndex];
		//std::cout << "  currentchar =" << currentChar << std::endl;
		//flag(22);
		if(currentChar == ' ' || currentChar == '	') // if the char is a space or a tab
		{
			currentSpace = true;
			//std::cout<< "current space true" << std::endl;
		}

		if(currentSpace != previousSpace) // ie  start/end of data
		{
			spaceIndex[spaceCounter] = currentIndex;
                        //std::cout<< "start/end data" << std::endl;
			spaceCounter++;
		}

                //std::cout <<  "mid cycle, currentSpace = " << currentSpace << std::endl;
                //std::cout <<  "mid cycle, previousSpace = " << previousSpace << std::endl;

		if(currentSpace == true)
		{
			currentSpace = false;
			previousSpace = true;
		}
		else
		{
			previousSpace = false;
		}
		//std::cout <<  "end of cycle, currentSpace = " << currentSpace << std::endl;
                //std::cout <<  "end of cycle, previousSpace = " << previousSpace << std::endl;
		currentIndex++;
	}
	flag(23);
	spaceIndex[4] =  inputLine.length();
	flag(231);
	int sizeStore[3] = {spaceIndex[0],spaceIndex[2] - spaceIndex[1],spaceIndex[4] - spaceIndex[3]};
        //std::cout << "sizeStore: " << sizeStore[1] << std::endl;
        //std::cout << "space Index[4]: " << spaceIndex[4] << std::endl;
        //std::cout << "space index [3]: " << spaceIndex[3] << std::endl;

	std::cout << "inputLine.length(): " << inputLine.length() << std::endl;
	flag(232);
	int indexStore[3] = {0,spaceIndex[1],spaceIndex[3]};
	flag(233);
	char indexChars[sizeStore[0]];
	flag(234);
	char nameChars[sizeStore[1]];
	flag(235);
	char floorSpaceChars[sizeStore[2]];
	flag(24);
	/*
        std::cout << "sizeStore: " << sizeStore[0] << std::endl;
        std::cout << "sizeStore: " << sizeStore[1] << std::endl;
        std::cout << "sizeStore: " << sizeStore[2] << std::endl;
        std::cout << "space Index[0]: " << spaceIndex[0] << std::endl;
        std::cout << "space Index[1]: " << spaceIndex[1] << std::endl;
        std::cout << "space Index[2]: " << spaceIndex[2] << std::endl;
        std::cout << "space Index[3]: " << spaceIndex[3] << std::endl;
	*/

	for(int a = 0; a < 3; a++)
	{
		for(int b = 0; b < sizeStore[a]; b++)
		{
			switch(a)
			{
				case 0:
				{
					flag(25);
					indexChars[b] = inputLine[b + indexStore[a]];
					char currentChar = inputLine[b + indexStore[a]];
					int currentCharAsInt = (int)currentChar - '0';
					inputIndex = inputIndex * 10 + (int)currentChar - '0';
                                        //std::cout << "  indexCharsAsInt= " << currentCharAsInt << std::endl;
				}
				break;
                                case 1:
				{
					flag(26);
					nameChars[b] = inputLine[b + indexStore[a]];
                                        ///std::cout << "  nameChars[b]= " << nameChars[b] << std::endl;
                                }
				break;
                                case 2:
				{
					flag(27);
					floorSpaceChars[b] = inputLine[b + indexStore[a]];
					char currentChar = inputLine[b + indexStore[a]];
					int currentCharAsInt =  (int)currentChar - '0';
					inputFloorSpace = inputFloorSpace * 10 + (int)currentChar - '0';
                                        //std::cout << "  floorSpaceCharsAsInt= " << currentCharAsInt << std::endl;
                                }
				break;

			}
		}
	}
	flag(28);
	inputName = nameChars;
	(*input).index = inputIndex;
	(*input).name = inputName;
	(*input).floorSpace = inputFloorSpace;
  std::cout<< "inputIndex: " << inputIndex << std::endl;
  std::cout<< "inputName: " << inputName << std::endl;
  std::cout<< "inputFloorSpace: " << inputFloorSpace << std::endl;
}

void getIntInput(int *inputVariable, int min, int max)
{
	bool validInput = false;
	while(validInput == false)
	{
		bool continueChecking = true;
		std::string inputValueString;
		int inputValue = 0;
		getline(std::cin,inputValueString);
		bool negativeValue = false;
		for(int a = 0; a < inputValueString.length(); a++)
		{
			if((inputValueString[a] >= '0' && inputValueString[a] <= '9') || inputValueString[a] == '-' || inputValueString[a] == '+')
			{
				switch(inputValueString[a])
				{
					case '-':
					{
						negativeValue != negativeValue;
					}
					break;
					default:
					{
						inputValue = inputValue*10 + ((int)inputValueString[a] - '0');
					}
			 	}
			}
			else
			{
				std::cout << "Expecting integer, invalid character entered" << std::endl;
				continueChecking = false;
				break;
			}
		}
		if(negativeValue)
		{
			inputValue *= -1;
		}
		if(inputValue < max && inputValue > min && continueChecking == true)
		{
			*inputVariable = inputValue;
			validInput = true;
		}
		else
		{
			std::cout << "Incorrect input, please re-enter" << std::endl;
			continueChecking = false;
		}
	}
}

void getStringInput(std::string *inputVariable, char type)
{
	bool validInput = false;
	std::string inputValueString;
	while(validInput == false)
	{
		getline(std::cin, inputValueString);
		std::cout << "You entered (internal): " << inputValueString << std::endl;
		switch(type)
		{
			case 'u':
			case 'U':
			{
				bool upper = true;
				for(int a = 0; a <= (inputValueString.length()-1); a++)
				{
					if(inputValueString[a] > 122 || inputValueString [a] < 97)
					{
						upper = false;
						std::cout << "Invalid input, expecting lower case, please re-enter" << std::endl;
						std::cout << "On char" << inputValueString[a] << std::endl;
						break;
					}
					else
					{
						validInput = true;
					}
				}
			}
			break;
			case 'b':
			case 'B':
			{
				// do nought
			}
			break;
			case 'l':
			case 'L':
			{
				bool lower = true;
				for(int a = 0; a <= (inputValueString.length()-1); a++)
				{
					if(inputValueString[a] > 90 || inputValueString [a] < 65)
					{
						lower = false;
						std::cout << "Invalid input, expecting upper case, please re-enter" << std::endl;
						break;
					}
					else
					{
						validInput = true;
					}
				}
			}
			break;
		}
	}
	*inputVariable = inputValueString;
}

void getFloatInput(int *inputVariable, float min, float max)
{
	bool validInput = false;
	while(validInput == false)
	{
		std::string inputString;
		int negative = 0;
		int negativePosition = 0;
		int nonNumericChar = 0;
		for(int a = 0; a < inputString.length(); a++)
		{
			if(inputString[a] == '-')
			{
				negative++;
				negativePosition = a;
			}
			if((inputString[a] > '9' || inputString[a] < '0') && inputString[a] != '.' && inputString[a] != '-')
			{
				nonNumericChar++;
			}
		}
		if(negative > 1)
		{
			std::cout << "Invalid input, too many '-' characters" << std::endl;
			continue;
		}
		if(negativePosition != 0)
		{
			std::cout << "Invalid input, '-' not at beginning of number" << std::endl;
			continue;
		}
		if(nonNumericChar > 0)
		{
			std::cout << "Invalid input, non numerical characters entered" << std::endl;
			continue;
		}
		float outputValue = 0;
		int state = 0; // state to hold uilding mode of numbers;
		int initialPosition =0;
		int dotPosition = 0;
		if(negative == 1)
		{
			initialPosition++;
		}
		for(int b = initialPosition; b < inputString.length(); b++)
		{
			switch(state)
			{
				case 0:
				{
					if(inputString[a] != '.')
					{
						outputValue = outputValue * 10 + (float)(inputString[a] - '0');
					}
					else
					{
						state++;
						dotPosition = a;
					}
				}
				break;

				case 1:
				{
					outputValue = outputValue + ((float)(inputString[a] - '0') * pow(10, dotPosition - a));
				}
				break;
			}
		}
		if(outputValue > max)
		{
			std::cout << "Invalid input, input greater than expected maximum" << std::endl;
			continue;
		}
		if(outputValue < min)
		{
			std::cout << "Invalid input, input greater than expected maximum" << std::endl;
			continue;
		}
		*inputVariable = outputValue;
		break;
	}
}

void flag(int flagNo)
{
	if(activation == true)
	{
		std::cout << "Flag " << flagNo << std::endl;
	}
}
