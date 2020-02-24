.PHONY: all clean

CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -g

all: primenumbers

clean:
		rm -rf primenumbers *.o
primenumbers: main.cpp program.cpp primes.cpp
		$(CC) $(CFLAGS) main.cpp program.cpp primes.cpp -o primenumbers
