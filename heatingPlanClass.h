class heatingPlanClass
{
  private:
    char Index;
    float initialCost;
    float heatingCostReduction;
    float initialDefaultHeatingCost = 0.015;// £/c/m^2/hr

  public:
    heatingPlanClass();
    void setIndex(char input);
    void setHeatingCostReduction(float input);
    void setInitialCost(float input);
    void setInitialDefaultHeatingCost(float input);

    char getIndex());
    float getHeatingCostReduction();
    float getInitialCost();
    float getInitialDefaultHeatingCost();
    // some stuff abt calc-ing stuff
}
