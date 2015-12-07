/**
   @author Pei Wang
 */

#include "BGMEngine.hpp"
#include <boost/random.hpp>
#include <math.h>

BGMEngine::BGMEngine(const BGMProduct& theProduct_,
                     const BGMVolModel& volModel_,
                     const std::vector<double>& spotForward_,
                     unsigned long NumOfPaths_
                     ) : NumOfPaths(NumOfPaths_)
{
    theProductPtr = &theProduct_;
    volModelPtr = &volModel_;    
    spotForwardPtr = &spotForward_;
    // need to use substeps to increase accuracy
    times = theProductPtr->getUnderlyingTimes();
    vols = volModelPtr->getVols(times);

    tenor = 1.;
    LIBORRates.resize(times.size());
    // LIBORRates[i][j]: written at j, delivered from i to i+1, i >= j
    for (int i = 0; i < times.size(); i++) {
        LIBORRates[i].resize(i+1);
        LIBORRates[i][0] = (*spotForwardPtr)[i];
    }
    numToRecord = 1;
}

std::vector<std::vector<double> > BGMEngine::currentMean() const
{
    std::vector<std::vector<double> > mean(resultsSoFar[0].size());
    for (int i = 0; i < mean.size(); i++) {
        mean[i].resize(i+1);
        for (int j = 0; j < mean[i].size(); j++) 
            mean[i][j] = 0.;
    }
       
    for (auto result : resultsSoFar) {
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                mean[i][j] += result[i][j] / resultsSoFar.size();   
            }
        }        
    }
    return mean;
}

std::map<unsigned long, std::vector<std::vector<double> > > 
BGMEngine::getLIBORRates() 
{
    // underlying times: from 0 to N-1
    // use the terminal rate (at N) as numeraire
    // L_i is martingale under measure of i+1
    // otherwise, has drift term depends on i+1 to N-1
    // evolve LIBORRates[i][0] to get LIBORRates[i][j]

    std::vector<double> W(LIBORRates.size(), 0.);

    unsigned long seed =12411;
    boost::mt19937 rng(seed);
    boost::normal_distribution<> norm(0.0, 1.0);
    boost::variate_generator<boost::mt19937&,
                             boost::normal_distribution<> > rand(rng, norm);

    // Monte Carlo --------------------------------------------------------
    for (unsigned long N = 0; N < NumOfPaths; N++) {

        // one path -------------------------------------------------------
        for (int j = 1; j < times.size(); j++) {
            W[j] = W[j-1] + rand()*sqrt(times[j] - times[j-1]);
        }

        double drift;    
        for (int i = LIBORRates.size() - 1; i > 0; i--) {
            drift = 0.;        
            for (int j = 1; j < LIBORRates[i].size(); j++) {
                for (int k = i+1; k < LIBORRates.size(); k++) {
                    drift += vols[k][j-1]*tenor*LIBORRates[k][j-1] / 
                        (1 + tenor*LIBORRates[k][j-1]) * vols[k][j-1] * 
                        LIBORRates[i][j-1] * (times[j] - times[j-1]);
                }
                LIBORRates[i][j] = LIBORRates[i][j-1] - drift + 
                    vols[i][j-1]*(W[j] - W[j-1]);
            //std::cout <<"L["<<i<<","<<j<<"]: "<< LIBORRates[i][j] 
            //          << ", drift: "<<drift<< std::endl;
            }
        }
        resultsSoFar.push_back(LIBORRates);
        // one path done --------------------------------------------------

        // save results every power of 2
        if ( N+1 == 2*numToRecord) {
            results[numToRecord] = currentMean();            
            numToRecord = 2*numToRecord;
        }
    }
    return results;
}

#include <iostream>
#include "BGMSwaption.hpp"
#include "BGMConstantVol.hpp"

int main() {
    BGMSwaption swaption;
    BGMConstantVol volModel;
    double f[10] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.91};
    std::vector<double> spotForward(f,f+10);

    BGMEngine bgm(swaption, volModel, spotForward, 10);
    
    std::map<unsigned long, std::vector<std::vector<double> > > LIBORRates;
    LIBORRates = bgm.getLIBORRates();

    for (auto rates : LIBORRates) {    
        std::cout << rates.first << std::endl;
        for (int i = 0; i < rates.second.size(); i++) {
            for (int j = 0; j < rates.second[i].size(); j++) {
                std::cout << rates.second[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
