/**
   @author Pei Wang
 */

#ifndef BLACK_FORMULAS
#define BLACK_FORMULAS

double PayersSwaption(double spotSwapRate, 
                      double strike, 
                      double start,
                      double end,
                      double annuity, 
                      double vol);
double ReceiversSwaption(double spotSwapRate, 
                         double strike, 
                         double start,
                         double end,
                         double annuity, 
                         double vol);
double Caplet(double spotForwardRate, 
              double strike, 
              double start,
              double end,
              double zcb, 
              double vol);
double Floorlet(double spotForwardRate, 
              double strike, 
              double start,
              double end,
              double zcb, 
              double vol);
#endif
