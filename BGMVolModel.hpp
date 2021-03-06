/**
   This is an abstract class for implementing different volatility models for 
   the BGM model.

   @author Pei Wang
 */

#ifndef BGM_VOL_MODEL
#define BGM_VOL_MODEL

#include <vector>

class BGMVolModel 
{
public:
    BGMVolModel() {}
    virtual std::vector<std::vector<double> > getVols(std::vector<int> times)
    const=0;
private:
};

#endif
