/**
   The AsianOption's interface is same as VanillaOption, the difference is
   this getPayOff() function will calculate payoff by looking at the arithmetic
   average of the input path.

   @author Pei Wang
 */

#ifndef ASIAN_OPTION
#define ASIAN_OPTION

#include "Instrument.hpp"
#include "PathGenerator.hpp"
#include <vector>

class AsianOption : public Instrument 
{
public:
    enum OptionType {call, put};
    AsianOption(OptionType optionType_,
                double expiry_,
                double strike_);
    virtual double getExpiry() const;
    virtual double getPayOff(const std::vector<double>& path) const;
private:
    OptionType optionType;
    double expiry;
    double strike;
};

#endif
