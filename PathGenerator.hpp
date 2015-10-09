#ifndef PATH_GENERATOR
#define PATH_GENERATOR

#include <vector>

class PathGenerator 
{
public:
    // generate real paths instead of risk neutral paths
    PathGenerator() {}
    virtual std::vector<double> getPaths()=0;
    virtual void reset()=0;
    virtual double getExpiry()=0;
private:
};

#endif
