#ifndef HEDGING_P_N_L
#define HEDGING_P_N_L

#include "PathGenerator.hpp"
#include "HedgingStrategy.hpp"

class HedgingPnL 
{
public:
    HedgingPnL(PathGenerator& path_,
               HedgingStrategy& strategy_,
               double r_,
               double initialValue_);
    double getPnL();
private:
    PathGenerator* pathPtr;
    HedgingStrategy* strategyPtr;
    double r;
    double initialValue;
};

#endif
