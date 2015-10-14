/**
   This is an abstract class, all instruments should inherit this class.

   @author Pei Wang
 */


#ifndef INSTRUMENT
#define INSTRUMENT

#include <vector>

class Instrument 
{
public:
    Instrument() {}
    virtual double getExpiry() const=0;
    virtual double getPayOff(const std::vector<double>& path) const=0;
private:
};

#endif
