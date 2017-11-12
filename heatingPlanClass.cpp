#include "heatingPlanClass.h"

heatingPlanClass::heatingPlanClass()
{
  index = (char)0;
  heatingCostReduction = 0.0;
  initialCost = 0.0;
}

void heatingPlanClass::setIndex(char input)
{
  index = input;
}

void heatingPlanClass::setHeatingCostReduction(float input)
{
  heatingCostReduction = input;
}

void heatingPlanClass::setInitialCost(float input)
{
  initialCost = input;
}

void heatingPlanClass::setHeatingCost(float input)
{
  heatingCost = input;
}

char heatingPlanClass::getIndex()
{
  return index;
}

float heatingPlanClass::getHeatingCostReduction()
{
  return heatingCostReduction;
}

float heatingPlanClass::getInitialCost()
{
  return initialCost;
}

float heatingPlanClass::getHeatingCost()
{
  return heatingCost;
}
