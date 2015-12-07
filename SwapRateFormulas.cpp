/**
   @author Pei Wang
 */

#include "SwapRateFormulas.hpp"

std::vector<double> SwapRates(std::vector<double> times,
                              std::vector<double> zcb,
                              unsigned long start,
                              unsigned long end)
{
    std::vector<double> swapRates(zcb.size());
    double annuity = 0;
    if (end > swapRates.size()) 
        end = swapRates.size();
    swapRates[0] = 0.0;
    for (unsigned long i = start+1; i < end; i++) {
        annuity += (times[i]-times[i-1])*zcb[i];
        swapRates[i] = (zcb[start] - zcb[i]) / annuity;
    }
    return swapRates;
}

double SwapAnnuity(std::vector<double> times,
                   std::vector<double> zcb,
                   unsigned long start,
                   unsigned long end)
{
    double annuity = 0;
    for (unsigned long i = start; i < end; i++) {
        annuity += (times[i+1]-times[i])*zcb[i+1];        
    }
    return annuity;
}

// all swaps starts at t = 0. 
// this is the reverse of SwapRates()
std::vector<double> ZCBCoTerminal(std::vector<double> times,
                                  std::vector<double> swapRates,
                                  double zcbSpot)
{
    std::vector<double> zcb(swapRates.size());
    zcb[0] = zcbSpot;
    double sum = 0.0;
    zcb[1] = zcb[0] / (1 + swapRates[1]*(times[1]-times[0]));
    for (unsigned long i = 1; i < swapRates.size(); i++) {
        zcb[i] = (zcb[0] - sum*swapRates[i]) 
            / (1 + (times[i]-times[i-1])*swapRates[i]);
        sum += (times[i]-times[i-1])*zcb[i];      
    }
    return zcb;
}

#include <iostream>

int main() {
    double timesTemp[] = {0.0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4};
    std::vector<double> times(timesTemp, timesTemp+9);
    double zcbTemp[] = {1, 0.9756, 0.94999,0.92397,0.898,0.87245,
                        0.84737,0.8229,0.799};
    std::vector<double> zcb(zcbTemp, zcbTemp+9);
    std::vector<double> swapRates;
    swapRates = SwapRates(times, zcb, 0, 9);
    for (auto s : swapRates) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;

    std::vector<double> zcbCoTerminal;
    //std::vector<double> times1(timesTemp+1, timesTemp+9);
    zcbCoTerminal = ZCBCoTerminal(times, swapRates, 1);
    for (auto z : zcbCoTerminal) {
        std::cout << z << std::endl;
    }
}
