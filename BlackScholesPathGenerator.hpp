#ifndef BLACK_SCHOLES_PATH_GENERATOR
#define BLACK_SCHOLES_PATH_GENERATOR

#include "PathGenerator.hpp"
#include <vector>

class BlackScholesPathGenerator : public PathGenerator
{
public:
    BlackScholesPathGenerator(double spot_, 
                              double drift_, 
                              double dvdnt_, 
                              double vol_, 
                              double expiry_,
                              unsigned long NumOfSteps_);
    virtual std::vector<double> getPaths();
    double getExpiry();
private:
    double spot;
    double drift;
    double dvdnt;
    double vol;
    double expiry;
    unsigned long NumOfSteps;
    std::vector<double> path;
};

#endif
