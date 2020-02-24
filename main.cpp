#include <iostream>
#include <string.h>
#include "program.hpp"

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

uint32_t readNumber(char *num)
{
    uint32_t i(0);
    while (*num != '\0')
    {
        if (*num >= '0' && *num <= '9')
        {
            i = i * 10 + (*num - '0');
            num += sizeof(char);
        }
        else
        {
            throw -3;
        }
    }
    return i;
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    Program p;
    uint32_t i;
    if (argc == 1)
    {
        std::cout << "print -help for call the command list\n";
    }
    else
    {
        try
        {

            for (i = 1; i < static_cast<uint32_t>(argc); ++i)
            {
                if (argv[i][0] == '-')
                {
                    if (strcmp(argv[i], "-search") == 0)
                    {
                        ++i;
                        p.setSeachMode(readNumber(argv[i]));

                    }
                    else if (strcmp(argv[i], "-number") == 0)
                    {
                        ++i;
                        p.setMax(readNumber(argv[i]));
                    }
                    else if (strcmp(argv[i], "-print") == 0)
                    {
                        if (i + 1 < static_cast<uint32_t>(argc) && argv[i+1][0] != '-')
                        {
                            ++i;
                            p.setFilename(argv[i]);
                        }
                        else
                        {
                            p.setFilename(nullptr);
                        }
                    }
                    else if (strcmp(argv[i], "-output") == 0)
                    {
                        ++i;
                        p.setSelect(readNumber(argv[i]));
                    }
                    else if (strcmp(argv[i], "-help") == 0)
                    {
                        printHelp();
                    }
                    else
                    {
                        throw 0;
                    }
                }
            }
            p.run();
        }
        catch (int a)
        {
            switch (a)
            {
                case 0:
                {
                    std::cout << "Unknown parameter " << '"' << argv[i] << '"' << std::endl;
                    break;
                }
                case -1:
                {
                    std::cout << "Indefind number of search mode!" << std::endl;
                    break;
                }
                case -2:
                {
                    std::cout << "Attempt to access the end of an infifnite array!" << std::endl;
                    break;
                }
                case -3:
                {
                    std::cout << "Unknown number" << argv[i] << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}
