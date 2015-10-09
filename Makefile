OBJS = HedgingPnL.o BlackScholesHedgingStrategy.o BlackScholesPathGenerator.o VanillaOption.o VanillaGreeks.o BlackScholesFormulas.o
CC = g++
DEBUG = -g
CFLAGS = -c  
LFLAGS = 

hedgePnL : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hedgePnL

HedgingPnL.o : HedgingPnL.hpp HedgingPnL.cpp BlackScholesHedgingStrategy.hpp BlackScholesHedgingStrategy.cpp BlackScholesPathGenerator.hpp BlackScholesPathGenerator.cpp VanillaOption.hpp VanillaOption.cpp
	$(CC) $(CFLAGS) HedgingPnL.cpp

BlackScholesHedgingStrategy.o : BlackScholesHedgingStrategy.hpp BlackScholesHedgingStrategy.cpp BlackScholesPathGenerator.hpp BlackScholesPathGenerator.cpp VanillaOption.hpp VanillaOption.cpp VanillaGreeks.hpp VanillaGreeks.cpp
	$(CC) $(CFLAGS) BlackScholesHedgingStrategy.cpp

BlackScholesPathGenerator.o : BlackScholesPathGenerator.hpp BlackScholesPathGenerator.cpp
	$(CC) $(CFLAGS) BlackScholesPathGenerator.cpp

VanillaOption.o : VanillaOption.hpp VanillaOption.cpp
	$(CC) $(CFLAGS) VanillaOption.cpp

VanillaGreeks.o : VanillaGreeks.hpp VanillaGreeks.cpp BlackScholesFormulas.hpp BlackScholesFormulas.cpp
	$(CC) $(CFLAGS) VanillaGreeks.cpp

BlackScholesFormulas.o : BlackScholesFormulas.hpp BlackScholesFormulas.cpp
	$(CC) $(CFLAGS) BlackScholesFormulas.cpp

