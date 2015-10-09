#ifndef BLACK_SCHOLES_PATH_GENERATOR
#define BLACK_SCHOLES_PATH_GENERATOR

#include "PathGenerator.hpp"
#include <vector>
#include <boost/random.hpp>
#include <boost/shared_ptr.hpp>

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
    virtual void reset();
    double getExpiry();
private:
    double spot;
    double drift;
    double dvdnt;
    double vol;
    double expiry;
    unsigned long NumOfSteps;
    std::vector<double> path;
    boost::shared_ptr<
        boost::variate_generator<boost::mt19937&,
                                 boost::normal_distribution<> > > 
    randPtr;
    boost::shared_ptr<boost::mt19937> rngPtr;
};

#endif
