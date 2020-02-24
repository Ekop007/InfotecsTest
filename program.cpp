#include <iostream>
#include "program.hpp"

Program::Program() : search_mode(0), max(100), select(0), print(false), filename(nullptr)
{
}

void Program::fileOutput(Primes &p)
{
    std::ofstream out;
    out.open(filename);
    if(search_mode == 0)
    {
        max = p.size();
    }
    switch (select)
    {
        case 0:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                out << p[i] << std::endl;
            }
            break;
        }
        case 1:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                out << p[p[i]-1] << std::endl;
            }
            break;
        }
        case 2:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                if (SophieGemanFilter(p, i))
                {
                    out << p[i] << std::endl;
                }
            }
            break;
        }
    }
    out.close();
}

void Program::consoleOutput(Primes &p)
{
    if(search_mode == 0)
    {
        max = p.size();
    }
    switch (select)
    {
        case 0:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                std::cout << p[i] << " ";
            }
            break;
        }
        case 1:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                std::cout << p[p[i]-1] << " ";
            }
            break;
        }
        case 2:
        {
            for(uint32_t i = 0; i < max; ++i)
            {
                if (SophieGemanFilter(p, i))
                {
                    std::cout << p[i] << " ";
                }
            }
            break;
        }
    }
    std::cout << "\n";
}

bool Program::SophieGemanFilter(Primes &p, uint32_t i)
{
    uint32_t num = 2 * p[i] + 1;
    uint32_t j = i;
    while (num > p[j])
    {
        ++j;
    }
    return (p[j] == num);
}

void Program::setSeachMode(uint32_t mode)
{
    search_mode = mode;
}

void Program::setMax(uint32_t number)
{
    max = number;
}

void Program::setSelect(uint32_t mode)
{
    select = mode;
}

void Program::setFilename(char *name)
{
    if (name != nullptr)
    {
        filename = name;
    }
    print = true;
}

void Program::run()
{
    if (search_mode == 0)
    {
        Primes p(max);
        if (print)
        {
            if (filename != nullptr)
            {
                fileOutput(p);
            }
            else
            {
                consoleOutput(p);
            }
        }

    }
    else if (search_mode == 1)
    {
        Primes p;
        if (print)
        {
            if (filename != nullptr)
            {
                fileOutput(p);
            }
            else
            {
                consoleOutput(p);
            }
        }
    }
    else
    {
        throw -1;
    }
}
