#include "VanillaOption.hpp"
#include <math.h>
#include <iostream>

VanillaOption::VanillaOption(OptionType optionType_, 
                             double expiry_, double strike_) 
    : optionType(optionType_), expiry(expiry_), strike(strike_)
{}

double VanillaOption::getExpiry() const { return expiry; }

double VanillaOption::getPayOff (double spot) const
{
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
    VanillaOption call(VanillaOption::put, 10., 100.);
    //std::cout << call.getExpiry() << " " << call.getPayOff(110.) << std::endl;
    VanillaOption* callPtr = &call;
    std::cout << callPtr->getExpiry() << "\n";
}
*/
