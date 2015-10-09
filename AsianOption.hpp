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
