# Instrument

## VanillaOption

---

# PathGenerator

## BlackScholesPathGenerator

---

# HedgingStrategy
Abstract class. Output a vector of number of instrument to hold. 

## BlackScholesHedgingStrategy
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


---

# MonteCarlo

---

# BlackScholesFormulas
# VanillaGreeks
