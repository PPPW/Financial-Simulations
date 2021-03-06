/**
   @author Pei Wang
 */

#ifndef PAY_OFF_FACTORY
#define PAY_OFF_FACTORY

#include "PayOff.hpp"
#include <string>
#include <map>

class PayOffFactory
{
public:
    // now can use CreatePayOffFunction as function pionter type
    typedef PayOff* (*CreatePayOffFunction)(double );
    // return a static instance
    static PayOffFactory& Instance();
    // insert a string and a function pointer into map
    void RegisterPayOff(std::string, CreatePayOffFunction);
    // search the map by input string, return the PayOff pointer
    PayOff* CreatePayOff(std::string PayOffId, double Strike);
    ~PayOffFactory() {}
private:
    // map of name and function pointer
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    // make constructors private, then it can only be created inside
    PayOffFactory() {}
    PayOffFactory(const PayOffFactory&) {}
    PayOffFactory& operator=(const PayOffFactory&) { return *this; }
};

#endif
