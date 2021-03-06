/**
   Black Scholes formulas for options.
   
   @author Pei Wang
 */

#ifndef BLACK_SCHOLES_FORMULAS
#define BLACK_SCHOLES_FORMULAS

// BS formula only need initial spot, not the value, so don't need to 
// take option objects as inputs
double BlackScholesCall(double spot, 
                        double strike, 
                        double expiry, 
                        double r, 
                        double dvdnt, 
                        double vol);

double BlackScholesPut(double spot, 
                       double strike, 
                       double expiry, 
                       double r, 
                       double dvdnt, 
                       double vol);

#endif
