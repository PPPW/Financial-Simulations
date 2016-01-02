/**
   g++ testPayOff.cpp PayOffRegistration.cpp PayOff.cpp PayOffFactory.cpp

   @author Pei Wang
 */

#include "PayOffHelper.hpp"
#include "PayOffFactory.hpp"
#include <string>
#include <iostream>

using namespace std;

int main() {
    double Strike;
    std::string name;

    cout << "Enter strike\n";
    cin >> Strike;
    cout << "\npay-off name\n";
    cin >> name;

    PayOff* PayOffPtr =
        PayOffFactory::Instance().CreatePayOff(name,Strike);

    if (PayOffPtr != NULL)
    {
        double Spot;
        cout << "\nspot\n";
        cin >> Spot;
        cout << "\n" << PayOffPtr->operator()(Spot) << "\n";
        delete PayOffPtr;
    }

    double tmp;
    cin >> tmp;
    return 0;
}
