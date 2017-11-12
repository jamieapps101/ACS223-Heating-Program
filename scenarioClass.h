#include <iostream>

struct efficiencyRatingsStructure
{
	char type;
	float initialCost;
	float heatingCostScale;
};

class scenarioClass
{
  private:
    char chosenffeciencyRating;
    struct efficiencyRatingsStructure efficiencyRatings[6];


  public:
    scenarioClass();
    void setEfficiencyRating(char &input);
    void printUpgradeOptions();

    float getInitalCost();
    float getSavings();
};
