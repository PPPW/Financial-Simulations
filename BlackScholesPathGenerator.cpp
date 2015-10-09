#include "BlackScholesPathGenerator.hpp"
#include <iostream>

BlackScholesPathGenerator::
BlackScholesPathGenerator(double spot_,                           
                          double drift_, 
                          double dvdnt_, 
                          double vol_,
                          double expiry_,
                          unsigned long NumOfSteps_) 
    : spot(spot_), drift(drift_), dvdnt(dvdnt_), vol(vol_), expiry(expiry_),
      NumOfSteps(NumOfSteps_)
{
    path.resize(NumOfSteps + 1);
    unsigned long seed =12411;
    rngPtr = boost::shared_ptr<boost::mt19937> ( new boost::mt19937(seed) );
    boost::normal_distribution<> norm(0.0, 1.0);

    randPtr = boost::shared_ptr<
        boost::variate_generator<boost::mt19937&,
                                 boost::normal_distribution<> > > 
        ( new boost::variate_generator<boost::mt19937&,
          boost::normal_distribution<> >(*rngPtr, norm) );
}

std::vector<double> BlackScholesPathGenerator::getPaths() 
{
    double currentSpot = spot;
    double increment = expiry/NumOfSteps;
    for (int i = 0; i <= NumOfSteps; i++) {
        path[i] = currentSpot;
        currentSpot *= exp( (drift-0.5*vol*vol)*increment
                            + vol*sqrt(increment)*(*randPtr)());        
    }
    return path;
}

void BlackScholesPathGenerator::reset() 
{
    rngPtr->seed(12411UL);
}

double BlackScholesPathGenerator::getExpiry() { return expiry; }
/*
#include <fstream>

int main() {
    BlackScholesPathGenerator pathGen(100, 0, 0, 0.2, 20, 1);
    std::vector<double> path = pathGen.getPaths();
    //std::ofstream fout;
    //fout.open("path.txt");
    for (int i = 0; i < path.size(); i++) {
        //fout << i << "\t" << path[i] << std::endl;
        std::cout << i << "\t" << path[i] << std::endl;
    }
    //fout.close();
    path = pathGen.getPaths();
    for (int i = 0; i < path.size(); i++) {
        std::cout << i << "\t" << path[i] << std::endl;
    }
    pathGen.reset();
    path = pathGen.getPaths();
    for (int i = 0; i < path.size(); i++) {
        std::cout << i << "\t" << path[i] << std::endl;
    }    
}
*/
