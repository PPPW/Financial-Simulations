/**
   @author Pei Wang
 */

#include "BlackScholesHedgingStrategy.hpp"
#include "VanillaGreeks.hpp"
#include <iostream>

BlackScholesHedgingStrategy::
BlackScholesHedgingStrategy(PathGenerator& path_,
                            VanillaOption& option_,
                            double r_,
                            double dvdnt_,
                            double vol_)
    : r(r_), dvdnt(dvdnt_), vol(vol_)
{
    pathPtr = &path_;
    optionPtr = &option_;
}


std::vector<double> BlackScholesHedgingStrategy::getHedgingStategy() 
{
    std::vector<double> path = pathPtr->getPaths();
    hedgingStrategy.resize(path.size());

    double (*greekPtr)(double, double, double, double, double, double);   
    VanillaOption::OptionType optionType = optionPtr->getType();
    double strike = optionPtr->getStrike();
    double expiry = optionPtr->getExpiry();
    switch (optionType) {
    case VanillaOption::call:
        greekPtr = DeltaCall;
        break;
    case VanillaOption::put:
        greekPtr = DeltaPut;
        break;
    default:
        std::cout << "unknown type! " << std::endl;
        exit(1);
    }

    for (int i = 0; i < path.size(); i++) {
        hedgingStrategy[i] = (*greekPtr)(path[i], strike, expiry, 
                                         r, dvdnt, vol);
    }

    return hedgingStrategy;
}
/*
#include "BlackScholesPathGenerator.hpp"

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

    //std::cout << path.size() << " " << strategy.size() << std::endl;

    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " " << strategy[i] << std::endl;
    }
    return 0;
}
*/
