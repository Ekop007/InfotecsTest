.PHONY all clean

CC = g++
CFLAGS = -g -Wall

all: primenumbers

clean:
            rm -rf primenumbers *.o
main.o: main.cpp primes.hpp
            g++ -c -o main.o main.cpp
primes.o: primes.cpp primes.hpp
            g++
