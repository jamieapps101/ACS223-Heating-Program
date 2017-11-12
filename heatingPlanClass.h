class heatingPlanClass
{
  private:
    char Index;
    float initialCost;
    float heatingCostReduction;
    const float initialHeatingCost = 0.015;// £/c/m^2/hr

  public:
    heatingPlanClass();
    void setIndex(char input);
    void setHeatingCostReduction(float input);
    void setInitialCost(float input);
    char getIndex());
    char getHeatingCostReduction();
    char getInitialCost();
    // some stuff abt calc-ing stuff
}
