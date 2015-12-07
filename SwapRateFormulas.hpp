/**
   Swap rate formulas.
   
   @author Pei Wang
 */

#ifndef SWAP_RATE_FORMULAS
#define SWAP_RATE_FORMULAS

#include <vector>

std::vector<double> SwapRates(std::vector<double> times,
                              std::vector<double> zcb,
                              unsigned long start,
                              unsigned long end);

double SwapAnnuity(std::vector<double> times,
                   std::vector<double> zcb,
                   unsigned long start,
                   unsigned long end);

std::vector<double> ZCBCoTerminal(std::vector<double> times,
                                  std::vector<double> swapRates,
                                  double zcbSpot);

#endif
