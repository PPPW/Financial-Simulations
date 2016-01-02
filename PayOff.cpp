/**
   M. Joshi's C++ design pattern PayOff3.cpp, slightly changed
   
   @author Pei Wang
 */

#include "PayOff.hpp"
#include <math.h>

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_) 
{}

double PayOffCall::operator () (double Spot) const
{ return fmax(Spot-Strike,0.0); }

//PayOff* PayOffCall::clone() const
//{ return new PayOffCall(*this); }

double PayOffPut::operator () (double Spot) const
{ return fmax(Strike-Spot,0.0); }

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{}

//PayOff* PayOffPut::clone() const
//{ return new PayOffPut(*this); }
