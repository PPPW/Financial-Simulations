/**
   @author Pei Wang
 */

#include "AsianOption.hpp"
#include <vector>
#include <iostream>
#include <math.h>

AsianOption::AsianOption(OptionType optionType_,          
                         double expiry_,                  
                         double strike_)
    : optionType(optionType_), expiry(expiry_), strike(strike_)
{}   

double AsianOption::getExpiry() const { return expiry; }

double AsianOption::getPayOff(const std::vector<double>& path) const 
{
    double meanSpot = 0.0;
    for (auto spot : path) {
        meanSpot += spot;
    }
    meanSpot /= path.size();
    switch (optionType) {
    case call:
        return fmax(meanSpot - strike, 0.0);
    case put:
        return fmax(strike - meanSpot, 0.0);
    default:
        throw("Invalid option type.");
    }
}
/*
int main() {
    AsianOption call(AsianOption::call, 10., 100.);

    double spots[] = {90, 100, 140};
    std::vector<double> path(spots, spots+3);

    std::cout << call.getPayOff(path) << "\n";
}
*/
