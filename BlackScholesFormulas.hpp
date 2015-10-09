/*
Since for different instruments the solution is very different, so here didn't
make it reusable. 
 */

#ifndef BLACKSCHOLESFORMULAS
#define BLACKSCHOLESFORMULAS

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
