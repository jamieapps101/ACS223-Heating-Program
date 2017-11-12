heatingPlanClass::heatingPlanClass();
{
  index = (char)0;
  heatingCostReduction = 0.0;
  initialCost = 0.0;
}

void heatingPlanClass::setIndex(char input);
{
  index = input;
}

void heatingPlanClass::setHeatingCostReduction(float input);
{
  heatingCostReduction = input;
}

void heatingPlanClass::setInitialCost(float input);
{
  initialCost = input;
}

void heatingPlanClass::setHeatingCost(float input);
{
  heatingCost = input;
}

char heatingPlanClass::getIndex());
{
  return index;
}

char heatingPlanClass::getHeatingCostReduction();
{
  return heatingCostReduction;
}

char heatingPlanClass::getInitialCost();
{
  return initialCost;
}

void heatingPlanClass::getInitialCost();
{
  return initialCost;
}
