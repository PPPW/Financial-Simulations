#include "BlackScholesFormulas.hpp"
#include <boost/math/distributions.hpp>
#include <math.h>
#include <iostream>

double BlackScholesCall(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol)
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spot/strike)+(r+vol*vol/2)*expiry ) / vol / sqrt(expiry);
    double d2 = d1 - vol*sqrt(expiry);
    return spot*exp(-dvdnt*expiry)*cdf(norm, d1) 
        - strike*exp(-r*expiry)*cdf(norm, d2);
}

double BlackScholesPut(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol)
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spot/strike)+(r+vol*vol/2)*expiry ) / vol / sqrt(expiry);
    double d2 = d1 - vol*sqrt(expiry);
    return -spot*exp(-dvdnt*expiry)*cdf(norm, -d1) 
        + strike*exp(-r*expiry)*cdf(norm, -d2);
}

int main() {
    double price = BlackScholesPut(100., 105., 20., 0.01/365, 0., 0.02); 
    std::cout << price << std::endl;
}
