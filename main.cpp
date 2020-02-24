#include <iostream>
#include "primes.hpp"



void printHelp()
{
    std::cout << "Hello. This program is desiged to count prime numbers.\n";
    std::cout << "Instruction:\n";
    std::cout << "-search <mode> - prime search mode. There are 2 modes:\n";
    std::cout << "        0 - range search with upper bound - default\n";
    std::cout << "        1 - search of a certain amount\n";
    std::cout << "-number <number> - search parameter - how many numbers will the program find or upper search boundary find. Default value - 100 \n";
    std::cout << "-print <filename> - print mode - output of found numbers in file. If there is no file name, the output is made to the console. Off by default\n";
    std::cout << "-output <number> - select output filter:\n";
    std::cout << "        0 - no filter - default\n";
    std::cout << "        1 - super-prime numbers\n";
    std::cout << "        2 - Sophie German prime numbers\n";
    std::cout << "-help - call the command list\n";
}

void printArray(Primes &p, uint32_t var, char *filename)
{

}

int main (int argc, char **argv)
{
    if (argc == 1)
    {
        Primes p(100);
    }
    else
    {

    }
    return 0;
}
