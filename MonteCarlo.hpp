#ifndef MONTE_CARLO
#define MONTE_CARLO

#include "Instrument.hpp"
#include <vector>

class MonteCarlo 
{
public:
    MonteCarlo(Instrument& instrument_, double spot_, double r_, 
               double dvdnt_, double vol_, unsigned long Dimensionality_);   
    std::vector<std::vector<double> > simulate();
private:
    Instrument* instrumentPtr;
    double spot;
    double r;
    double dvdnt;
    double vol;
    unsigned long Dimensionality;

    std::vector<std::vector<double> > results;
    std::vector<double> resultsSoFar;
    double expiry;
    double brownian;
    unsigned long pathsDone;
    double getOneResult() const;
    double currentMean() const;
    double currentStd() const;
};

#endif

