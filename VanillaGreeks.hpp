#ifndef VANILLA_GREEKS
#define VANILLA_GREEKS

double DeltaCall(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double DeltaPut(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double Gamma(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double Vega(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double RhoCall(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double RhoPut(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double ThetaCall(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

double ThetaPut(double spot, double strike, double expiry, 
                        double r, double dvdnt, double vol);

#endif
