#include "MonteCarlo.hpp"
#include "VanillaOption.hpp"
#include <boost/random.hpp>
#include <math.h>
#include <iostream>
#include <fstream>

MonteCarlo::MonteCarlo(Instrument& instrument_, double spot_, double r_, 
               double dvdnt_, double vol_, unsigned long Dimensionality_) 
    : spot(spot_), r(r_), dvdnt(dvdnt_), vol(vol_),
      Dimensionality(Dimensionality_)
{
    instrumentPtr = &instrument_;
    expiry = instrumentPtr->getExpiry();
    pathsDone = 0;
}

double MonteCarlo::getOneResult() const
{    
    double spotMaturity = spot*exp( (r-dvdnt)*expiry - vol*vol*expiry/2
                                   + vol*sqrt(expiry)*brownian );
    return (instrumentPtr->getPayOff(spotMaturity))*exp(-r*expiry);
}

double MonteCarlo::currentMean() const
{
    double sum = 0;
    for (auto result : resultsSoFar) {
        sum += result;
    }
    return sum / resultsSoFar.size();
}

double MonteCarlo::currentStd() const
{
    double sumSqr = 0;
    double mean = currentMean();
    for (auto result : resultsSoFar) {
        sumSqr += (result - mean) * (result - mean);
    }
    // sample standard deviation
    return sqrt( sumSqr / (resultsSoFar.size()-1) ); 
    
}

std::vector<std::vector<double> > MonteCarlo::simulate() 
{
    unsigned long seed =12411;  // set seed
    boost::mt19937 rng(seed);   // generate pseudo random number series
    boost::normal_distribution<> norm(0.0, 1.0);
    boost::variate_generator <boost::mt19937,boost::normal_distribution<> >
        randNorm(rng, norm);           // connect with normal distribution
        
    double currentResult;
    std::vector<double> currentResultNPath(2);
    for (unsigned long i = 0; i < Dimensionality; i++) {
        brownian = randNorm();
        //currentResult = brownian;
        currentResult = getOneResult();
        resultsSoFar.push_back(currentResult);
        pathsDone++;

        currentResultNPath[0] = currentMean();
        currentResultNPath[1] = pathsDone;
        results.push_back(currentResultNPath);
    }
    return results;
}

int main() {
    VanillaOption putOption(VanillaOption::call, 20., 105.);
    MonteCarlo MC = MonteCarlo(putOption, 100., 0.01/365, 0.0, 0.02, 
                               1000);
    std::vector<std::vector<double> > results = MC.simulate();

    std::ofstream fout;
    fout.open("MCoutput.txt");
    for ( auto result : results ) {
        fout << result[1] << "\t" << result[0] << std::endl;
    }
    fout.close();
}
