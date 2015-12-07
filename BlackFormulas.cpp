/**
   @author Pei Wang
 */

#include "BlackFormulas.hpp"
#include <boost/math/distributions.hpp>
#include <math.h>

double PayersSwaption(double spotSwapRate, 
                      double strike, 
                      double start,
                      double end,
                      double annuity, 
                      double vol) 
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spotSwapRate/strike)+0.5*vol*vol*start )
        / vol / sqrt(start);
    double d2 = d1 - vol*sqrt(start);
    return annuity*(spotSwapRate*cdf(norm,d1) 
                    - strike*cdf(norm,d2));    
}

double ReceiversSwaption(double spotSwapRate, 
                         double strike, 
                         double start,
                         double end,
                         double annuity, 
                         double vol) 
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spotSwapRate/strike)+0.5*vol*vol*start )
        / vol / sqrt(start);
    double d2 = d1 - vol*sqrt(start);
    return annuity*(-spotSwapRate*cdf(norm,-d1) 
                    + strike*cdf(norm,-d2));    
}

double Caplet(double spotForwardRate, 
              double strike, 
              double start,
              double end,
              double zcb, 
              double vol) 
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spotForwardRate/strike)+0.5*vol*vol*start )
        / vol / sqrt(start);
    double d2 = d1 - vol*sqrt(start);
    return zcb*(end-start)*(spotForwardRate*cdf(norm,d1) 
                            - strike*cdf(norm,d2));    
}

double Floorlet(double spotForwardRate, 
                double strike, 
                double start,
                double end,
                double zcb, 
                double vol) 
{
    boost::math::normal_distribution <> norm(0,1);
    double d1 = ( log(spotForwardRate/strike)+0.5*vol*vol*start )
        / vol / sqrt(start);
    double d2 = d1 - vol*sqrt(start);
    return zcb*(end-start)*(-spotForwardRate*cdf(norm,-d1) 
                            + strike*cdf(norm,-d2));    
}
/*
#include <iostream>

int main() {
    std::cout << Caplet(939.68, 1008.33, 0.833,1.833, 0.92, 0.09) << std::endl;
}
*/
