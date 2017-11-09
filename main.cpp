#include <iostream>
#include <string>
#include <fstream>
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
void getValidUserData(void * output, char type);

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
	struct officeStructure officeOptions[15];
        std::string tempString;
	int optionsCounter = 0;
	while(!inputFile.eof())
        {
	        getline(inputFile,tempString);
		//std::cout << tempString;
		//std::cout << std::endl;
		getInputData( &(officeOptions[counter]), tempString);
		optionsCounter++;
        }
	// ~read data from file

	// Close file stream 
	inputFile.close();
	// ~Close file stream

	//Ask user to Specify Office
	std::cout << "How many rooms would you like to specfiy?:" << std::endl;
	int rooms;
	getValidUserData(&rooms, 'n');
	std::cout << "For each of the following rooms, you must specify a type." << std::endl;
	std::cout << "From the input file, you have the following options to choose
	// ~Ask user to specify office
	return 0;
}

void getInputData( struct officeStructure *input, std::string inputLine)
{
	int inputIndex;
	std::string inputName;
	int inputFloorSpace;

	int spaceIndex[5];
	int spaceCounter = 0;

	bool previousSpace = false;
	bool currentSpace = false;

	char currentChar;
	int currentIndex = 0;

	while((currentChar = inputLine[currentIndex]) != '\n')
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
	char indexChars[sizeStore[0]];
	char nameChars[sizeStore[1]];
	char floorSpaceChars[sizeStore[2]];
	for(int a = 0; a < 3; a++)
	{
		for(int b = indexStore[a]; b < sizeStore[a]; b++)
		{
			switch(a)
			{
				case 0:
					indexChars[b] = inputLine[b];
					inputIndex = inputIndex * 10 + (int)((char)inputLine[b] - 48);
				break;
                                case 1:
					nameChars[b] = inputLine[b+indexStore[a]];
                                break;
                                case 2:
					floorSpaceChars[b] = inputLine[b + indexStore[a]];
					inputFloorSpace = inputFloorSpace * 10 + (int)((char)inputLine[b + indexStore[a]] - 48);
                                break;

			}
		}
	}
	(*input).index = inputIndex;
	(*input).name = inputName;
	(*input).floorSpace = inputFloorSpace;
}

void getValidUserData(void * output, char type)
{
	bool validInput = false;
	std::string inputValue;
	int stringLength;
	while(validInput == false)
	{
		std::cin >> inputValue;
		stringLength = inputValue.length();
		switch(type)
		{
			case 'n':
			{
				validInput = true;
				int valueStore;
				int x;
				while(x < stringLength && validInput == true)
				{
					if(inputValue[x] <= 9 && inputValue[x] >= 0)
					{
						valueStore = valueStore*10 + inputValue[x];
					}
					else
					{
						std::cout << "Sorry, I'm expecting an integer value with no other characters, please try again: " << std::endl;
						validInput = false;
						break;
					}
					int *intOutput = static_cast<int*>(output);
					*intOutput = valueStore;
				}
			}
			break;

			case 'C': // capital Letter
			{
				//cin >> inputValue;
				char inputChar = inputValue[0];
				if(inputChar >= 65 && inputChar <= 90) // aka a capital letter
				{
					//inputValue += 32; // convert to lowercase
					//inputValue *= -1; // flag to output it was entered as upper case
					//*output = inputChar;
					char *charOutput = static_cast<char*>(output);
					*charOutput = inputChar;
					validInput = true;
				}
				else
				{
					std::cout << "Sorry, I'm expecting an upper case letter, please try again: " << std::endl;
				}
			}
			break;

                        case 'c': // lower case Letter
			{
                                //cin >> inputValue;
				char inputChar = inputValue[0];
                                if(inputChar >= 97 && inputChar <= 122) // aka a capital letter
                                {
                                        //*output = inputChar;
					char *charOutput = static_cast<char*>(output);
					*charOutput = inputChar;
                                        validInput = true;
                                }
                                else
                                {
                                        std::cout << "Sorry, I'm expecting a lower case letter, please try again: " << std::endl;
                                }
			}
                        break;

                        case 'a': // any Letter
			{
                                //cin >> inputValue;
				char inputChar = inputValue[0];
                                if(inputChar >= 65 && inputChar <= 90 || inputChar >= 97 && inputChar <= 122) // aka a letter
                                {
                                        //*output = inputChar;
					char *charOutput = static_cast<char*>(output);
                                        *charOutput = inputChar;
					validInput = true;
                                }
                                else
                                {
                                        std::cout << "Sorry, I'm expecting a letter, please try again: " << std::endl;
                                }
			}
                        break;



			default:
				std::cout << "Internal error" << std::endl;
			break;
		}
	}
}
