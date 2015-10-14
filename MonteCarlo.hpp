/**
   The MonteCarlo class takes an instrument and a random path, run simulate for
   given number of times, record the result every power of 2. 
   
   @author Pei Wang
 */

#ifndef MONTE_CARLO
#define MONTE_CARLO

#include "Instrument.hpp"
#include "PathGenerator.hpp"
#include <vector>

class MonteCarlo 
{
public:
    MonteCarlo(Instrument& instrument_, 
               PathGenerator& pathGen_, 
               double r_, 
               double dvdnt_, 
               double vol_, 
               unsigned long Dimensionality_);   
    std::vector<std::vector<double> > simulate();
protected:
    virtual double getOneResult(std::vector<double> path) const;
private:
    Instrument* instrumentPtr;
    PathGenerator* pathGenPtr;
    double r;
    double dvdnt;
    double vol;
    unsigned long Dimensionality;
    double expiry;

    std::vector<std::vector<double> > results;
    std::vector<double> resultsSoFar;
    unsigned long numToRecord;

    double currentMean() const;
    //double currentStd() const;
};

#endif

