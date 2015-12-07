/**
   @author Pei Wang
 */

#include "BlackScholesFormulas.hpp"
#include <boost/math/distributions.hpp>
#include <math.h>

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
/*
#include <iostream>
#include <fstream>
int main() {
    std::ofstream fout;
    fout.open("option.txt");
    for (int i = 0; i< 10; i++) {
        for (double spot = 100; spot < 110; spot+=1.0) {
            double price = 
                BlackScholesPut(spot, 105., i+0.1, 0.01/365, 0., 0.02); 
            fout << spot <<'\t'<< price << std::endl;
        }
    }    
    fout.close();
}
*/
