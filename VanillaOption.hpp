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
    double getExpiry() const;
    double getPayOff(double spot) const;
private:
    OptionType optionType;
    double expiry;
    double strike;
};

#endif
