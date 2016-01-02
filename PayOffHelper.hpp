/**
   @author Pei Wang
 */

#ifndef PAY_OFF_HELPER
#define PAY_OFF_HELPER

#include "PayOffFactory.hpp"
#include "PayOff.hpp"
#include <string>

template<class T>
class PayOffHelper
{
public:
    // create a factory instance and add string to map
    PayOffHelper(std::string);
    // return a function pointer on heap
    static PayOff* Create(double);
private:    
};

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike);
}

#endif
