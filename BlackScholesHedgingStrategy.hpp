/**
   The BlackScholesHedgingStrategy class takes a random path and an instrument,
   calculates a vector of number of stocks to hold using Delta.
   
   @author Pei Wang
 */

#ifndef BLACK_SCHOLES_HEDGING_STRATEGY
#define BLACK_SCHOLES_HEDGING_STRATEGY

#include "HedgingStrategy.hpp"
#include "VanillaOption.hpp"
#include <vector>

class BlackScholesHedgingStrategy : public HedgingStrategy
{
public:
    BlackScholesHedgingStrategy(PathGenerator& path_,
                                VanillaOption& option_,
                                double r_,
                                double dvdnt_,
                                double vol_);
    virtual std::vector<double> getHedgingStategy();
private:
    PathGenerator* pathPtr;
    VanillaOption* optionPtr;
    std::vector<double> hedgingStrategy;
    double r;
    double dvdnt;
    double vol;
};

#endif
