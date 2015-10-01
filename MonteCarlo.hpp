#ifndef MONTECARLO
#define MONTECARLO

#include "Instrument.hpp"
#include <vector>

class MonteCarlo 
{
public:
    MonteCarlo(Instrument& instrument_, double spot_, double r_, 
               double dvdnt_, double vol_, unsigned long Dimensionality_);   
    double simulate();
private:
    Instrument* instrumentPtr;
    double spot;
    double r;
    double dvdnt;
    double vol;
    unsigned long Dimensionality;

    std::vector<double> results;
    double expiry;
    double brownian;
    double getOneResult() const;
    double currentMean() const;
    double currentStd() const;
};

#endif

