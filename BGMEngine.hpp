/**
   @author Pei Wang
 */

#ifndef BGM_ENGINE
#define BGM_ENGINE

#include "BGMProduct.hpp"
#include "BGMVolModel.hpp"

class BGMEngine 
{
public:
    BGMEngine(const BGMProduct& theProduct_,
              const BGMVolModel& volModel_,
              const std::vector<double>& spotForward_,
              unsigned long NumOfPaths_
              );
    std::vector<std::vector<double> > getLIBORRates();
private:
    const BGMProduct* theProductPtr;
    const BGMVolModel* volModelPtr;
    const std::vector<double>* spotForwardPtr;
    unsigned long NumOfPaths;
    std::vector<std::vector<double> > LIBORRates;
    std::vector<int> times;
    std::vector<std::vector<double> > vols;
    double tenor;
};

#endif
