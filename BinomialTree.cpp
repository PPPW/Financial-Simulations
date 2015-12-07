/**
   @author Pei Wang
 */

#include "BinomialTree.hpp"
#include <iostream>
#include <math.h>
#include <vector>

BinomialTree::BinomialTree(double spot_,
                           double r_,
                           double dvdnt_,
                           double vol_,
                           double expiry_,
                           unsigned long NumOfPeriods_) 
    : spot(spot_), r(r_), dvdnt(dvdnt_), 
      vol(vol_), expiry(expiry_), NumOfPeriods(NumOfPeriods_)
{
    TheTree.resize(NumOfPeriods);
    buildTree();
}

void BinomialTree::buildTree() 
{
    double increment = expiry / NumOfPeriods;
    // Cox-Ross-Rubinstein
    double u = exp(vol*sqrt(increment));
    double d = 1/u;
    q = (exp(r*increment)-d) / (u-d);
    // Jarrow-Rudd
    //double u = exp(vol*sqrt(increment)-vol*vol*0.5);
    //double d = exp(-vol*sqrt(increment)-vol*vol*0.5);
    //q = 0.5;
    
    TheTree[0].resize(1);
    TheTree[0][0] = spot;
    for (unsigned long i = 1; i < NumOfPeriods; i++) {
        TheTree[i].resize(i+1);
        for (unsigned long j = 0; j < i; j++) 
            TheTree[i][j] = d*TheTree[i-1][j];
        TheTree[i][i] = u*TheTree[i-1][i-1];
    }
}

void BinomialTree::printTree() const 
{
    for (unsigned long i = 0; i < TheTree.size(); i++) {
        for (unsigned long j = 0; j <= i; j++) 
            std::cout << TheTree[i][j] << " ";
        std::cout << std::endl;
    }
    return;
}

double BinomialTree::priceEuropeanOption(const VanillaOption& option) const
{
    std::vector<std::vector<double> > priceTree(TheTree);
    for (long j = NumOfPeriods-1; j >= 0; j--) {
        priceTree[NumOfPeriods-1][j] = option.getPayOff(
        std::vector<double> {TheTree[NumOfPeriods-1][j]});
    }
    
    for (long i = NumOfPeriods-2; i >= 0; i--) {
        for (long j = i; j >= 0; j--)
            priceTree[i][j] = (q*priceTree[i+1][j+1] + (1-q)*priceTree[i+1][j]);
    }
    return priceTree[0][0];
}

#include "VanillaOption.hpp"

int main() {
    BinomialTree bt(100, 0.1, 0.0, 0.2, 10, 5);
    bt.printTree();
    
    VanillaOption call(VanillaOption::put, 10., 100.);
    std::cout << bt.priceEuropeanOption(call) << std::endl;
}
