class heatingPlanClass
{
  private:
    char index;
    float initialCost;
    float heatingCostReduction;
    float heatingCost;// £/c/m^2/hr

  public:
    heatingPlanClass();
    void setIndex(char input);
    void setHeatingCostReduction(float input);
    void setInitialCost(float input);
    void setHeatingCost(float input);

    char getIndex();
    float getHeatingCostReduction();
    float getInitialCost();
    float getHeatingCost();
    // some stuff abt calc-ing stuff
};
