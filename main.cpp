#define activation false
#define activation2 false
#define activation3 false

#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "room.h"
#include "heatingPlanClass.h"
#include "scenarioClass.h"
#include <iomanip>
// Main of heating calculator program
// Written by Jamie Apps
// 7/11/17

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
void flag2(int flagNo);
void flag3(int flagNo);
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
	std::cout << "Reading data:" << std::endl;
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
		flag(12);
		std::cout <<  tempString << std::endl;
		getInputData( &(officeOptions[optionsCounter-1]), tempString);
		flag(13);
	}
	// ~read data from file

	// Close file stream
	inputFile.close();
	// ~Close file stream

	//Ask user to Specify Office
	std::cout << std::endl << "How many rooms would you like to specfiy?:" << std::endl;
	int rooms;
	getIntInput(&rooms, 1, 20);
	room userOffice[rooms];
	std::cout << std::endl << "For each of the following rooms, you must specify a type." << std::endl;
	std::cout << "From the input file, you have the following options to choose:" << std::endl;
	std::cout << std::setw(5) << "Index";
	std::cout << std::setw(20) << "Name";
	std::cout << std::setw(20) << "FloorSpace(m^2)" << std::endl;
	for(int a = 0; a < optionsCounter; a++)
	{
		std::cout << std::setw(5) << officeOptions[a].index;
		std::cout << std::setw(20) << officeOptions[a].name;
		std::cout << std::setw(20) << officeOptions[a].floorSpace << std::endl;
	}
	std::cout << std::endl << "For each of the rooms, please specify a type by typing the index number" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": " << std::endl;
		int inputValue;
		getIntInput(&inputValue, 1, optionsCounter);
		std::cout << std::endl;
		userOffice[a].setTypeIndex(inputValue);
		//userOffice[a].setType(inputValue);
	}
	std::cout << std::endl << "You have entered rooms of the following types:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		int roomType = userOffice[a].getTypeIndex();
		std::cout << a << ": " << officeOptions[roomType+1].name << std::endl;
		userOffice[a].setType(officeOptions[roomType+1].name);
	}
	// ~Ask user to specify office
	// Ask user to heating options
	heatingPlanClass heatingPlan;
	//heatingPlan.heatingPlanClass();
	std::cout << std::endl << "And now for each of these rooms, please specify how many hours per day you" << std::endl;
	std::cout << "would like them to be heated for:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": " << std::endl;
		float inputValue;
		getFloatInput(&inputValue,0,24);
		std::cout << std::endl;
		userOffice[a].setHoursPerDayHeated(inputValue);
	}
	std::cout << std::endl << "Please specify how many days per year you would like them to be heated for:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": " << std::endl;
		float inputValue;
		getFloatInput(&inputValue,0,365);
		std::cout << std::endl;
		userOffice[a].setDaysPerYearHeated(inputValue);
	}
	std::cout << std::endl << "Would you like to use the default heating cost of  £0.015/C/m^2/hr ('d') or" << std::endl;
	std::cout << "enter a custom value ('c') ? " << std::endl;
	bool usefulResponse = false;
	while(usefulResponse == false)
	{
		std::string heatingChoiceString;
		getStringInput(&heatingChoiceString, 'b');
		std::cout << std::endl;
		switch(heatingChoiceString[0])
		{
			case 'c':
			case 'C':
			{
				std::cout << "Please enter a new heating cost in £/C/m^2/hr:" << std::endl;
				usefulResponse = true;
				float input;
				getFloatInput(&input,0,1);
				std::cout << std::endl;
				heatingPlan.setHeatingCost(input);
			}
			break;

			case 'd':
			case 'D':
			{
				usefulResponse = true;
				heatingPlan.setHeatingCost(0.015);
			}
			break;

			default:
			{
				std::cout << "the first letter of that wasn't a particuarly useful response, try 'd' or 'c' next time" << std::endl;
			}
			break;
		}
	}
	std::cout << std::endl << "Please specify what temperature you would like each room to increase by:" << std::endl;
	for(int a = 0; a < rooms; a++)
	{
		std::cout << "Room " << a << ": ";
		float inputValue;
		getFloatInput( &inputValue,0,24);
		userOffice[a].setHeatingTemp(inputValue);
	}
	std::cout << std::endl << "Here is a list of the annual cost of heating a room:" << std::endl;
	float currentTotalAnnualCostforBuilding = 0;
	for(int a = 0; a < rooms; a++)
	{
		std::cout<< "For room number " << a << " which is of type " << userOffice[a].getType(); // getType not working////////////////////////////////
		float cost = userOffice[a].getHoursPerDayHeated() * userOffice[a].getDaysPerYearHeated() * userOffice[a].getHeatingTemp() * heatingPlan.getHeatingCost();
		currentTotalAnnualCostforBuilding += cost;
		std::cout << "it would cost £" << cost << std::endl;
	}
		// ~Ask user to heating options
		// Compare savings
	std::cout << std::endl << "Now we will investigate the initial costs and payback times of installing an energy efficiency" << std::endl;
	std::cout << "upgrade package. The following are a list of the potential upgrades:" << std::endl;
	scenarioClass senarios[3];
	senarios[0].printUpgradeOptions();
	std::cout << std::endl;
	std::cout << "These upgrades will be a building wide upgrade, so will be automatrically applied to each room" << std::endl;
	std::cout << "We will run 3 senarios to test, where each senario will apply a certain upgrade, please select" << std::endl;
	std::cout << "from the upgrades above by inputting a package letter:"<<std::endl;
	for(int a = 0; a < 3; a++)
	{
		std::cout << "Senario " << a << std::endl;
		char packageSelected = 'x';
		while(packageSelected == 'x')
		{
			std::string inputString = "";
			getStringInput(&inputString, 'b');
			if(inputString[0] < 97)
			{
				inputString[0] += 32;
			}

			if(inputString[0] == 'a' || inputString[0] == 'b' || inputString[0] == 'c' || inputString[0] == 'd' || inputString[0] == 'e' || inputString[0] == 'f')
			{
				packageSelected = inputString[0];
			}
			else
			{
				std::cout << "Incorrect letter chosen, please renter" << std::endl << std::endl;
			}
		}
		senarios[a].setEfficiencyRating(packageSelected);
		std::cout << std::endl;

		std::cout <<  "Before the upgrade, the cost is: " << currentTotalAnnualCostforBuilding << std::endl;
		std::cout << std::endl;

		int initialUpgradeCost = 0;
		int totalFloorSpace = 0;
		for(int b = 0; b < rooms; b++)
		{
			totalFloorSpace += userOffice[a].getFloorSpace();
		}
		float currentScenarioUpgradeCost = senarios[a].getInitialCost()*totalFloorSpace;
		std::cout <<  "For this upgrade, the initial cost will be: " <<  currentScenarioUpgradeCost << std::endl;
		float newTotalAnnualCostforBuilding =  currentTotalAnnualCostforBuilding*senarios[a].getSavings();
		std::cout <<  "While the new annual cost will be: " <<  newTotalAnnualCostforBuilding << std::endl;
		float diffAnnualCost = currentTotalAnnualCostforBuilding - newTotalAnnualCostforBuilding;
		std::cout <<  "This is a yearly saving of: " <<  diffAnnualCost << std::endl;
		float paybacktime = currentScenarioUpgradeCost/diffAnnualCost;
		std::cout <<  "This will therefore take: " <<  paybacktime << " years to pay off" << std::endl <<std::endl;
		senarios[a].setUpgradeCost(currentScenarioUpgradeCost);
		senarios[a].setPaybackPeriod(paybacktime);
	}
   std::cout << std::endl;
	 std::cout <<  "In summary: " << std::endl;
	 std::cout <<  std::setw(11) << "Scenario:";
	 std::cout <<  std::setw(11) << "Upgrade Cost(£):";
	 std::cout <<  std::setw(11) << "Payback time(days):" << std::endl;
	 int bestScenario = 0;
	 int lowestPaybackTime = 100000;
	 for(int a = 0; a < 3; a++)
	 {
		 std::cout <<  std::setw(11) << a;
		 std::cout <<  std::setw(11) << senarios[a].getUpgradeCost();
		 std::cout <<  std::setw(11) << senarios[a].getPaybackPeriod() << std::endl;
		 if(senarios[a].getPaybackPeriod() < lowestPaybackTime)
		 {
			 lowestPaybackTime = senarios[a].getPaybackPeriod();
			 bestScenario = a;
		 }
	 }
	 std::cout << std::endl;
	std::cout <<  "Therefore the best scenario based on payback period is scenario "<< bestScenario << std::endl;
	std::cout <<  "Which is a model of efficiency upgrade: " << senarios[bestScenario].getEfficiencyRating()  << std::endl;
	// ~Compare savings
	return 0;
}


void getInputData( struct officeStructure *input, std::string inputLine)
{
	std::string inputIndex = "";
	int inputIndexInt = 0;
	std::string inputName = "";
	std::string inputFloorSpace = "";
	int inputFloorSpaceInt = 0;
	int intialNamePosition = 0;
	int state = 0;
	bool previousState = true;
	for(int a = 0; a < inputLine.length(); a++)
	{
		if(inputLine[a] != (char)32 && inputLine[a] != (char)9)
		{
			previousState = true;
			switch(state)
			{
				case 0:
				{
					inputIndexInt = inputIndexInt * 10 + (int)(inputLine[a] - '0');
				}
				break;
				case 1:
				{
					inputName += inputLine[a];
				}
				break;
				case 2:
				{
					inputFloorSpaceInt = inputFloorSpaceInt * 10 + (int)(inputLine[a] - '0');
				}
				break;
			}
		}
		else
		{
			if(previousState == true)
			{
				state++;
				previousState = false;
				if(state == 1)
				{
					intialNamePosition = a;
				}
			}
		}
	}
	(*input).index = inputIndexInt;
	(*input).name = "";
	(*input).name = inputName;
	(*input).floorSpace = inputFloorSpaceInt;
}

void getIntInput(int *inputVariable, int min, int max)
{
	bool validInput = false;
	flag2(1);
	while(validInput == false)
	{
		std::string inputString = "0";
		int negative = 0;
		int negativePosition = 0;
		int nonNumericChar = 0;
		getline(std::cin, inputString);
		flag2(2);
		for(int a = 0; a < inputString.length(); a++)
		{
			flag2(3);
			if(inputString[a] == '-')
			{
				negative++;
				negativePosition = a;
				flag2(4);
			}
			if((inputString[a] > '9' || inputString[a] < '0')  && inputString[a] != '-')
			{
				flag2(5);
				nonNumericChar++;
			}
		}

		if(nonNumericChar > 0)
		{
			std::cout << "Invalid input, non numerical characters entered" << std::endl;
			flag2(6);
			continue;
		}
		if(negative > 1)
		{
			std::cout << "Invalid input, too many '-' characters" << std::endl;
			flag2(7);
			continue;
		}
		if(negativePosition != 0)
		{
			std::cout << "Invalid input, '-' not at beginning of number" << std::endl;
			flag2(8);
			continue;
		}

		int outputValue = 0;
		//int state = 0; // state to hold uilding mode of numbers;
		int initialPosition =0;
		int dotPosition = 0;
		if(negative == 1)
		{
			flag2(9);
			initialPosition++;
		}
		for(int a = initialPosition; a < inputString.length(); a++)
		{
			flag2(10);
				outputValue = outputValue * 10 + (int)(inputString[a] - '0');
		}
		if(negative == 1)
		{
			flag2(10.5);
			outputValue *= -1;
		}
		//std::cout << "output value: " << outputValue << std::endl;
		if(outputValue > max)
		{
			flag2(11);
			std::cout << "Invalid input, input greater than expected maximum" << std::endl;
			continue;
		}
		if(outputValue < min)
		{
			flag2(12);
			std::cout << "Invalid input, input less than expected minimum" << std::endl;
			continue;
		}
		flag2(13);
		*inputVariable = outputValue;
		break;
	}
}

void getStringInput(std::string *inputVariable, char type)
{
	bool validInput = false;
	std::string inputValueString = "0";
	flag3(1);
	while(validInput == false)
	{
		getline(std::cin, inputValueString);
		//std::cout << "You entered (internal): " << inputValueString << std::endl;
		flag3(2);
		switch(type)
		{
			case 'u':
			case 'U':
			{
				flag3(3);
				bool upper = true;
				for(int a = 0; a <= (inputValueString.length()-1); a++)
				{
					flag3(4);
					if(inputValueString[a] > 122 || inputValueString [a] < 97)
					{
						flag3(5);
						upper = false;
						std::cout << "Invalid input, expecting lower case, please re-enter" << std::endl;
						std::cout << "On char" << inputValueString[a] << std::endl;
						break;
					}
					else
					{
						flag3(6);
						validInput = true;
					}
				}
			}
			break;

			case 'b':
			case 'B':
			{
				flag3(6);
				validInput = true;
				// do nought
			}
			break;

			case 'l':
			case 'L':
			{
				flag3(7);
				bool lower = true;
				for(int a = 0; a <= (inputValueString.length()-1); a++)
				{
					flag3(8);
					if(inputValueString[a] > 90 || inputValueString [a] < 65)
					{
						flag3(9);
						lower = false;
						std::cout << "Invalid input, expecting upper case, please re-enter" << std::endl;
						break;
					}
					else
					{
						flag3(10);
						validInput = true;
					}
				}
			}
			break;
		}
		flag3(11);
	}
	flag3(12);
	*inputVariable = inputValueString;
	//std::cout << "at output this was: " << *inputVariable << std::endl;
}

void getFloatInput(float *inputVariable, float min, float max)
{
	bool validInput = false;
	while(validInput == false)
	{
		std::string inputString = "0";
		int negative = 0;
		int negativePosition = 0;
		int nonNumericChar = 0;
		getline(std::cin, inputString);
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
		for(int a = initialPosition; a < inputString.length(); a++)
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
		if(negative == 1)
		{
			outputValue *= -1;
		}
		if(outputValue > max)
		{
			std::cout << "Invalid input, input greater than expected maximum" << std::endl;
			continue;
		}
		if(outputValue < min)
		{
			std::cout << "Invalid input, input less than expected minimum" << std::endl;
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

void flag2(int flagNo)
{
	if(activation2 == true)
	{
		std::cout << "Flag " << flagNo << std::endl;
	}
}

void flag3(int flagNo)
{
	if(activation3 == true)
	{
		std::cout << "Flag " << flagNo << std::endl;
	}
}
