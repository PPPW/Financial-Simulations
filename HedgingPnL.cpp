#include "HedgingPnL.hpp"
#include "BlackScholesHedgingStrategy.hpp"
#include "BlackScholesPathGenerator.hpp"
#include "VanillaOption.hpp"
#include <iostream>
#include <math.h>

HedgingPnL::HedgingPnL(PathGenerator& path_,
                       HedgingStrategy& strategy_,
                       double r_,
                       double initialValue_)
    : r(r_), initialValue(initialValue_)
{
    pathPtr = &path_;
    strategyPtr = &strategy_;
}


double HedgingPnL::getPnL() 
{
    std::vector<double> path = pathPtr->getPaths();
    std::vector<double> strategy = strategyPtr->getHedgingStategy();
    
    double expiry = pathPtr->getExpiry();
    double increment = expiry / path.size();
    double currentValue = initialValue;
    double currentCash = currentValue - strategy[0]*path[0];

    for (unsigned long i = 1; i < path.size(); i++) {
        currentValue = currentCash*exp(r*increment) 
            + strategy[i-1]*path[i];
        currentCash = currentValue - strategy[i]*path[i];
    }
    return currentValue;
}

int main() {
    BlackScholesPathGenerator pathGen(100, 0, 0, 0.2, 20, 10);
    std::vector<double> path = pathGen.getPaths();

    VanillaOption callOption(VanillaOption::call, 20., 110.);
         
    BlackScholesHedgingStrategy BSstrategy(pathGen,
                                           callOption,
                                           0.1,
                                           0.0,
                                           0.2);
    std::vector<double> strategy = BSstrategy.getHedgingStategy();

    HedgingPnL hedgingPnL(pathGen, BSstrategy, 0.1, 300);

    
    std::cout << hedgingPnL.getPnL() << std::endl;

    return 0;
}
