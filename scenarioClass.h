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
    char chosenEffeciencyRating;
    struct efficiencyRatingsStructure efficiencyRatings[6];
		float upgradeCost;
		float paybackPeriod;

  public:
    scenarioClass();
    void setEfficiencyRating(char &input);
    void printUpgradeOptions();
		void setUpgradeCost(float &input);
		void setPaybackPeriod(float &input);

		char getEfficiencyRating();
    float getInitialCost();
    float getSavings();
		float getUpgradeCost();
		float getPaybackPeriod();
		int paybackPeriodInDays();
};
