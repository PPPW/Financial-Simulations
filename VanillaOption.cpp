/**
   @author Pei Wang
 */

#include "VanillaOption.hpp"
#include <math.h>
#include <iostream>

VanillaOption::VanillaOption(OptionType optionType_, 
                             double expiry_, 
                             double strike_) 
    : optionType(optionType_), expiry(expiry_), strike(strike_)
{}

VanillaOption::OptionType VanillaOption::getType() const 
{ return optionType; }

double VanillaOption::getExpiry() const { return expiry; }

double VanillaOption::getStrike() const { return strike; }

double VanillaOption::getPayOff (const std::vector<double>& path) const
{
    // vanilla option depends on the spot price at maturity
    double spot = path[path.size()-1];
    switch (optionType) {
    case call:
        return fmax(spot - strike, 0.0);
    case put:
        return fmax(strike - spot, 0.0);
    default:
        throw("Invalid option type.");
    }
}
/*
int main() {
    VanillaOption call(VanillaOption::call, 10., 100.);
    std::vector<double> spot(2);
    spot[0] = 100.;
    spot[1] = 110.;
    std::cout << call.getPayOff(spot) << std::endl;
}
*/

