#ifndef INSTRUMENT
#define INSTRUMENT

class Instrument 
{
public:
    Instrument() {}
    virtual double getExpiry() const=0;
    virtual double getPayOff(double spot) const=0;
private:
};

#endif
