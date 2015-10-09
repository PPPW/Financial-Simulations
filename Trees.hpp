#ifndef TREES
#define TREES

#include "VanillaOption.hpp"
#include <vector>

class Trees
{
public:
    Trees() {}
    std::vector<std::vector<double> > TheTree;
    virtual double priceEuropeanOption(const VanillaOption& option) const=0;
private:
};

#endif
