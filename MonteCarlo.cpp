/**
   @author Pei Wang
 */

#include "MonteCarlo.hpp"
#include <boost/random.hpp>
#include <math.h>
#include <iostream>

MonteCarlo::MonteCarlo(Instrument& instrument_, 
                       PathGenerator& pathGen_,  
                       double r_, 
                       double dvdnt_, 
                       double vol_, 
                       unsigned long Dimensionality_) 
    : r(r_), dvdnt(dvdnt_), vol(vol_),
      Dimensionality(Dimensionality_)
{
    instrumentPtr = &instrument_;
    pathGenPtr = &pathGen_;
    expiry = instrumentPtr->getExpiry();
    numToRecord = 1;
}

double MonteCarlo::getOneResult(std::vector<double> path) const
{    
    return ( instrumentPtr->getPayOff(path) )*exp(-r*expiry);
}

double MonteCarlo::currentMean() const
{
    double sum = 0;
    for (auto result : resultsSoFar) {
        sum += result;
    }
    return sum / resultsSoFar.size();
}
/*
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
*/
std::vector<std::vector<double> > MonteCarlo::simulate() 
{
    double currentResult;
    std::vector<double> currentResultNPath(2);
    std::vector<double> path;
    for (unsigned long i = 0; i < Dimensionality; i++) {
        path = pathGenPtr->getPaths();
        currentResult = getOneResult(path);
        resultsSoFar.push_back(currentResult);
        if ( i+1 == 2*numToRecord) {
            currentResultNPath[0] = currentMean();
            currentResultNPath[1] = i+1;
            results.push_back(currentResultNPath);
            numToRecord = 2*numToRecord;
        }
    }
    return results;
}

#include "VanillaOption.hpp"
#include "AsianOption.hpp"
#include "BlackScholesPathGenerator.hpp"
#include <fstream>

int main() {
    /*
    VanillaOption callOption(VanillaOption::call, 20., 105.);
    BlackScholesPathGenerator pathGen(100, 0, 0, 0.2, 20, 1);
    */
    AsianOption callOption(AsianOption::call, 20., 105.);
    BlackScholesPathGenerator pathGen(100, 0, 0, 0.2, 20, 5);

    MonteCarlo MC = MonteCarlo(callOption, pathGen, 0.01/365, 0.0, 0.02, 
                               1500);
    std::vector<std::vector<double> > results = MC.simulate();

    std::ofstream fout;
    fout.open("MCoutput.txt");
    for ( auto result : results ) {
        fout << result[1] << "\t" << result[0] << std::endl;
    }
    fout.close();
}

