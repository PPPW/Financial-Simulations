/**
   The VanillaOption class. The getPayoff() function takes a path of spot
   prices, only look at the last element, which in the current version is
   considered to be the spot at maturity. 

   @author Pei Wang
 */

#ifndef VANILLAOPTION
#define VANILLAOPTION

#include "Instrument.hpp"
#include <vector>

class VanillaOption : public Instrument 
{
public:
    enum OptionType {call, put};
    VanillaOption(OptionType optionType_, 
                  double expiry_,
                  double strike_);
    OptionType getType() const;   
    double getExpiry() const;
    double getStrike() const;
    double getPayOff(const std::vector<double>& path) const;
private:
    OptionType optionType;
    double expiry;
    double strike;
};

#endif
