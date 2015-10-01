#include "MonteCarlo.hpp"
#include "VanillaOption.hpp"
#include <boost/random.hpp>
#include <math.h>
#include <iostream>

MonteCarlo::MonteCarlo(Instrument& instrument_, double spot_, double r_, 
               double dvdnt_, double vol_, unsigned long Dimensionality_) 
    : spot(spot_), r(r_), dvdnt(dvdnt_), vol(vol_),
      Dimensionality(Dimensionality_)
{
    instrumentPtr = &instrument_;
    std::vector<double> results;
    expiry = instrumentPtr->getExpiry();
}

double MonteCarlo::getOneResult() const
{    
    double spotMaturity = spot*exp( (r-dvdnt)*expiry - vol*vol*expiry/2
                                   + vol*sqrt(expiry)*brownian );
    return instrumentPtr->getPayOff(spotMaturity);
}

double MonteCarlo::currentMean() const
{
    double sum = 0;
    for (auto result : results) {
        sum += result;
    }
    return sum / results.size();
}

double MonteCarlo::currentStd() const
{
    double sumSqr = 0;
    double mean = currentMean();
    for (auto result : results) {
        sumSqr += (result - mean) * (result - mean);
    }
    return sqrt( sumSqr / (results.size()-1) ); // sample standard deviation
}

double MonteCarlo::simulate() 
{
    unsigned long seed =12411;  // set seed
    boost::mt19937 rng(seed);   // generate pseudo random number series
    boost::normal_distribution<> norm(0.0, 1.0);
    boost::variate_generator <boost::mt19937,boost::normal_distribution<> >
        randNorm(rng, norm);           // connect with normal distribution
        
    double currentResult;
    for (unsigned long i = 0; i < Dimensionality; i++) {
        brownian = randNorm();
        //currentResult = brownian;
        currentResult = getOneResult();
        results.push_back(currentResult);
    }
    std::cout << "std is " << currentStd() << std::endl;
    return currentMean()*exp(-r*expiry);
}

int main() {
    VanillaOption putOption(VanillaOption::call, 20., 105.);
    MonteCarlo MC = MonteCarlo(putOption, 100., 0.01/365, 0.0, 0.02, 
                               1000000);
    // expect to get 6.645
    std::cout << MC.simulate() << std::endl;
}
