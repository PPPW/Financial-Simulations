/**
   @author Pei Wang
 */

#ifndef BGM_SWAPTION
#define BGM_SWAPTION

#include "BGMProduct.hpp"

class BGMSwaption : public BGMProduct 
{
public:
    BGMSwaption() {}
    std::vector<int> getUnderlyingTimes() const;
    //std::vector<int> getEvolutionTimes() const { return std::vector<int>{0}; }
    //void reset() {}
    //bool doNextStep() { return false; }
private:
};

std::vector<int> BGMSwaption::getUnderlyingTimes() const 
{
    std::vector<int> times(10);
    for (int i = 0; i < 10; i++) {
        times[i] = i;
    }
    return times;
}

#endif
