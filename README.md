Computing projects in M. Joshi's ``The concept and practice of mathematical finance``.

# Instrument
Abstract class. 

Include:

API:

```
Instrument() {}
virtual double getExpiry() const=0;
virtual double getPayOff(double spot) const=0;
```

## VanillaOption

Include:	   
Instrument.hpp

API:

```
enum OptionType {call, put};
VanillaOption(OptionType optionType_, 
              double expiry_,
              double strike_);
OptionType getType() const;   
double getExpiry() const;
double getStrike() const;
double getPayOff(double spot) const;
```

---

# PathGenerator
Abstract class. 

Include:
vector

API:

```
PathGenerator() {}                       
virtual std::vector<double> getPaths()=0;
virtual double getExpiry()=0;            
```

## BlackScholesPathGenerator

Include:
boost/random.hpp
boost/shared_ptr.hpp

API:

```
BlackScholesPathGenerator(double spot_, 
                          double drift_, 
                          double dvdnt_, 
                          double vol_, 
                          double expiry_,
                          unsigned long NumOfSteps_);
virtual std::vector<double> getPaths();
double getExpiry();
```

---

# HedgingStrategy
Abstract class. 

Include:
PathGenerator.hpp
vector

API:

```
HedgingStrategy() {}                               
virtual std::vector<double> getHedgingStategy()=0; 
```

## BlackScholesHedgingStrategy
Include:


API:

```
BlackScholesHedgingStrategy(PathGenerator& path_,
                            VanillaOption& option_,
                            double r_,
                            double dvdnt_,
                            double vol_);
virtual std::vector<double> getHedgingStategy();
```

---

# HedgingPnL

Include: 
PathGenerator.hpp
HedgingStrategy.hpp

API:

```
HedgingPnL(PathGenerator& path_,      
           HedgingStrategy& strategy_,
           double r_,                 
           double initialValue_);     
double getPnL();                      
```

---

# MonteCarlo

Include:
Instrument.hpp
vector

API:

```
MonteCarlo(Instrument& instrument_,           
           double spot_,                      
           double r_,                         
           double dvdnt_,                     
           double vol_,                       
           unsigned long Dimensionality_);    
std::vector<std::vector<double> > simulate(); 
```

---

# BlackScholesFormulas
Include:

API:

```
double BlackScholesCall(double spot, 
                        double strike, 
                        double expiry, 
                        double r, 
                        double dvdnt, 
                        double vol);
double BlackScholesPut(double spot, 
                       double strike, 
                       double expiry, 
                       double r, 
                       double dvdnt, 
                       double vol);
```

# VanillaGreeks
Include:

API:
```
double DeltaCall(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);
double DeltaPut(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);
double Gamma(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);double Vega(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);
double RhoCall(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);double RhoPut(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);double ThetaCall(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);
double ThetaPut(double spot, double strike, 
						 double expiry, double r, 
						 double dvdnt, double vol);
```

