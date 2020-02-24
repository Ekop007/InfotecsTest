#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <fstream>
#include "primes.hpp"

class Program
{
public:
    Program();
    void fileOutput(Primes &p);
    void consoleOutput(Primes &p);
    bool SophieGemanFilter(Primes &p, uint32_t i);
    void setSeachMode(uint32_t mode);
    void setMax(uint32_t number);
    void setSelect(uint32_t mode);
    void setFilename(char *name);
    void run();

private:
    uint32_t search_mode;
    uint32_t max;
    uint32_t select;
    bool print;
    char *filename;
};

#endif // PROGRAM_HPP
