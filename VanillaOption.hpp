#ifndef VANILLAOPTION
#define VANILLAOPTION

#include "Instrument.hpp"

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
    double getPayOff(double spot) const;
private:
    OptionType optionType;
    double expiry;
    double strike;
};

#endif
