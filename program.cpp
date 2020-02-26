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
            auto lmd1 = [&p] (uint32_t index)
            {
                uint32_t i = index - 1;
                while (i > 0 && p[i] >= index)
                {
                    if (p[i] == index)
                    {
                        return true;
                    }
                }
                return false;
            };
            for(uint32_t i = 0; i < max; ++i)
            {
                if (lmd1(i))
                {
                    out << p[i] << std::endl;
                }
            }
            break;
        }
        case 2:
        {
            auto lmd2 = [&p] (uint32_t index)
            {
                uint32_t num = 2 * p[index] + 1;
                uint32_t j = index;
                while (num > p[j])
                {
                    ++j;
                }
                return (p[j] == num);
            };
            for(uint32_t i = 0; i < max; ++i)
            {
                if (lmd2(i))
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
            auto lmd1 = [&p] (uint32_t index)
            {
                uint32_t i = index - 1;
                while (i > 0 && p[i] >= index)
                {
                    if (p[i] == index)
                    {
                        return true;
                    }
                }
                return false;
            };
            for(uint32_t i = 0; i < max; ++i)
            {
                if (lmd1(i))
                {
                    std::cout << p[i] << " ";
                }
            }
            break;
        }
        case 2:
        {
            auto lmd2 = [&p] (uint32_t index)
            {
                uint32_t num = 2 * p[index] + 1;
                uint32_t j = index;
                while (num > p[j])
                {
                    ++j;
                }
                return (p[j] == num);
            };
            for(uint32_t i = 0; i < max; ++i)
            {
                if (lmd2(i))
                {
                    std::cout << p[i] << " ";
                }
            }
            break;
        }
    }
    std::cout << "\n";
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
