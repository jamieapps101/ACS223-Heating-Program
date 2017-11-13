#include <iostream>
#include <iomanip>
#include "scenarioClass.h"
#include <string>

scenarioClass::scenarioClass()
{
  float initialCostArray[] = {3.2, 12.75,32.20,45.33,77.80,143.50};
  for(int a = 0; a < 6; a++)
  {
    efficiencyRatings[a].type = (char)('A' + a);
    efficiencyRatings[a].initialCost = initialCostArray[5-a];
    if(a == 0)
    {
      efficiencyRatings[a].heatingCostScale = 0.67;
    }
    else
    {
        efficiencyRatings[a].heatingCostScale = 1.0 - ((6-(float)a)*0.05);
    }
  }
  upgradeCost = 0;
  paybackPeriod = 0;
}

void scenarioClass::printUpgradeOptions()
{
  std::cout << std::setw(14) << "Package";
  std::cout << std::setw(29) << "Initial upgrade cost: ";
  std::cout << std::setw(36)<< "Original Heating cost Scale: " << std::endl;
  for(int a = 0; a < 6; a++)
  {
    std::cout << std::setw(14) << efficiencyRatings[a].type << ", ";
    std::cout << std::setw(19)  << efficiencyRatings[a].initialCost << " £/m^2, ";
    char percentageChar = 37;
    std::cout << std::setw(33) << efficiencyRatings[a].heatingCostScale*100 << percentageChar << std::endl;
  }
}

void scenarioClass::setEfficiencyRating(char &input)
{
  chosenEffeciencyRating = input;
}

void scenarioClass::setUpgradeCost(float &input)
{
  upgradeCost = input;
}

void scenarioClass::setPaybackPeriod(float &input)
{
  paybackPeriod = input;
}

char scenarioClass::getEfficiencyRating()
{
  return chosenEffeciencyRating;
}

float scenarioClass::getInitialCost()
{
  return efficiencyRatings[ (int)(chosenEffeciencyRating - 'a')].initialCost;
}

float scenarioClass::getSavings()
{
  return efficiencyRatings[ (int)(chosenEffeciencyRating - 'a')].heatingCostScale;
}

float scenarioClass::getUpgradeCost()
{
    return upgradeCost;
}

float scenarioClass::getPaybackPeriod()
{
  return paybackPeriod;
}

int scenarioClass::paybackPeriodInDays()
{
  int years = 0;
  int days = 0;;
  float paybackPeriodCopy = paybackPeriod;
  while(paybackPeriodCopy > 1)
  {
    years++;
    paybackPeriodCopy--;
  }
  days = years * 365;

}
