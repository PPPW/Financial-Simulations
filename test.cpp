#include <iostream>
#include <boost/random.hpp>

class A 
{
public:
    A()
    {
        unsigned long seed =12411;
        rng(seed);
        boost::normal_distribution<> norm(0.0, 1.0);          
        randNorm(rng, norm);
        //randPtr = new boost::variate_generator<boost::mt19937&,
        //                         boost::normal_distribution<> > (*rngPtr, norm);        
        //std::cout << (*randPtr)() << std::endl;
        std::cout << randNorm() << std::endl;
    }
    ~A() 
    { 
        //delete randPtr; 
        //delete rngPtr; 
    }
    double getRandom() 
    {
        return randNorm();
        //return (*randPtr)();
    }        
private:
    boost::mt19937 rng;
    boost::variate_generator<boost::mt19937&,boost::normal_distribution<> >    
    randNorm;
};


int main() {
    A a;
    std::cout << a.getRandom() << std::endl;
}
