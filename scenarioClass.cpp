#include <iostream>
#include scenarioClass.h

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
        efficiencyRatings[a].heatingCostScale = 1.0 - ((6-(float)a)*0.05)
    }
  }
}

void printUpgradeOptions()
{
  for(int a = 0; a < 6; a++)
  {
    std::cout << "Package: " << efficiencyRatings[a].type << ", ";
    std::cout << "Initial upgrade cost: " << efficiencyRatings[a].initialCost << " £/m^2, ";
    char percentageChar = 37;
    std::cout << "Original Heating cost Scale: " << efficiencyRatings[a].heatingCostScale*100 << percentageChar << std::endl;
  }
}

void scenarioClass::setEfficiencyRating(char &input)
{
  chosenffeciencyRating = input;
}

float scenarioClass::getInitalCost()
{

}

float scenarioClass::getSavings()
{

}
