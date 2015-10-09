#include "BinomialTree.hpp"
#include <iostream>
#include <math.h>

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
    double u = exp(vol*sqrt(increment));
    double d = 1/u;
    
    TheTree[0].resize(1);
    TheTree[0][0] = spot;
    for (unsigned long i = 1; i < NumOfPeriods; i++) {
        TheTree[i].resize(i+1);
        for (unsigned long j = 0; j < i; j++) 
            TheTree[i][j] = d*TheTree[i-1][j];
        TheTree[i][i] = u*TheTree[i-1][i-1];
    }
}

double BinomialTree::priceEuropeanOption(const VanillaOption& option) const
{
    std::vector<std::vector<double> > priceTree(TheTree);
    for (long j = NumOfPeriods-1; j >= 0; j--)
        priceTree[NumOfPeriods-1][j] = 
            option.getPayOff(TheTree[NumOfPeriods-1][j]);

    for (long i = NumOfPeriods-2; i >= 0; i--) {
        for (long j = i; j >= 0; j--)
            priceTree[i][j] = 0.5*(priceTree[i+1][j+1] + priceTree[i+1][j]);
    }
    return priceTree[0][0];
}

int main() {
    BinomialTree bt(100, 0.1, 0.0, 0.2, 10, 5);
    std::vector<std::vector<double> > tree = bt.TheTree;

    for (unsigned long i = 0; i < tree.size(); i++) {
        for (unsigned long j = 0; j <= i; j++) 
            std::cout << tree[i][j] << " ";
        std::cout << std::endl;
    }

    VanillaOption call(VanillaOption::put, 10., 100.);
    std::cout << bt.priceEuropeanOption(call) << std::endl;
}
