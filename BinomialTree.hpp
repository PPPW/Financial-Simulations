/**
   The BinomialTree class generates the binomial tree and uses the tree to 
   price different instruments. 
   The default model is Cox-Ross-Rubinstein. 

   @author Pei Wang
 */


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
    void printTree() const;
    virtual double priceEuropeanOption(const VanillaOption& option) const;
private:
    double spot;
    double r;
    double dvdnt;
    double vol;
    double expiry;
    double NumOfPeriods;
    void buildTree();
    double q; // q is model dependent
};

#endif
