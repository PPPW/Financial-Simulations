/**
   This is an abstract class, all hedging strategies should inherit this class.

   @author Pei Wang
 */

#ifndef HEDGING_STRATEGY
#define HEDGING_STRATEGY

#include "PathGenerator.hpp"
#include <vector>

class HedgingStrategy 
{
public:
    HedgingStrategy() {}
    virtual std::vector<double> getHedgingStategy()=0;
private:
};

#endif
