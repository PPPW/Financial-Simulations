OBJS = MonteCarlo.o VanillaOption.o
CC = g++
DEBUG = -g
CFLAGS = -c -std=c++11
LFLAGS = -std=c++11

mc : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mc

MonteCarlo.o : MonteCarlo.hpp MonteCarlo.cpp VanillaOption.hpp VanillaOption.cpp
	$(CC) $(CFLAGS) MonteCarlo.cpp

VanillaOption.o : VanillaOption.hpp VanillaOption.cpp
	$(CC) $(CFLAGS) VanillaOption.cpp
