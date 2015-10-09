#ifndef BINOMIAL_TREE
#define BINOMIAL_TREE

#include "Trees.hpp"
#include "VanillaOption.hpp"
#include <vector>

class BinomialTree : public Trees
{
public:
    BinomialTree(double spot_,
                 double r_,
                 double dvdnt_,
                 double vol_,
                 double expiry_,
                 unsigned long NumOfPeriods_);
    std::vector<std::vector<double> > TheTree;
    virtual double priceEuropeanOption(const VanillaOption& option) const;
private:
    double spot;
    double r;
    double dvdnt;
    double vol;
    double expiry;
    double NumOfPeriods;
    void buildTree();   
};

#endif
