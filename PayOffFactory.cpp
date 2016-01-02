/**
   @author Pei Wang
 */

#include "PayOffFactory.hpp"
#include <iostream>

using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId,
                        CreatePayOffFunction CreatorFunction)
{
    TheCreatorFunctions.insert(pair<string,CreatePayOffFunction>
                                (PayOffId,CreatorFunction));
    //TheCreatorFunctions[PayOffId] = CreatorFunction;
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId,
                                      double Strike)
{
    map<string, CreatePayOffFunction>::const_iterator
                       i = TheCreatorFunctions.find(PayOffId);
    //if (TheCreatorFunctions.count(PayOffId) == 0)
    if  (i == TheCreatorFunctions.end())
    {
        std::cout << PayOffId << " is an unknown payoff" << std::endl;
        return NULL;
    }
    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}
