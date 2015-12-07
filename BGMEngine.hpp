/**
   @author Pei Wang
 */

#ifndef BGM_ENGINE
#define BGM_ENGINE

#include "BGMProduct.hpp"
#include "BGMVolModel.hpp"
#include <map>

class BGMEngine 
{
public:
    BGMEngine(const BGMProduct& theProduct_,
              const BGMVolModel& volModel_,
              const std::vector<double>& spotForward_,
              unsigned long NumOfPaths_
              );
    std::map<unsigned long, std::vector<std::vector<double> > > getLIBORRates();
private:
    const BGMProduct* theProductPtr;
    const BGMVolModel* volModelPtr;
    const std::vector<double>* spotForwardPtr;
    unsigned long NumOfPaths;
    std::vector<std::vector<double> > LIBORRates;
    std::vector<int> times;
    std::vector<std::vector<double> > vols;
    double tenor;

    std::map<unsigned long, std::vector<std::vector<double> > > results;
    std::vector<std::vector<std::vector<double> > > resultsSoFar;
    unsigned long numToRecord;

    std::vector<std::vector<double> > currentMean() const;
    
};

#endif
