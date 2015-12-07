/**
   @author Pei Wang
 */

#ifndef BGM_CONSTANT_VOL
#define BGM_CONSTANT_VOL

#include "BGMVolModel.hpp"

class BGMConstantVol : public BGMVolModel 
{
public:
    BGMConstantVol() {}
    std::vector<std::vector<double> > getVols(std::vector<int> times) const;
private:
};

std::vector<std::vector<double> > 
BGMConstantVol::getVols(std::vector<int> times) const 
{
    std::vector<std::vector<double> > vols;
    vols.resize(times.size());
    for (int i = 0; i < times.size(); i++) {
        vols[i].resize(i+1);
        for (int j = 0; j < i+1; j++) {
            vols[i][j] = 0.2;
        }
    }
    return vols;
}

#endif
