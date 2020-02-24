#include <cmath>
#include <string.h>
#include <fstream>
#include "primes.hpp"

Primes::Primes() : maxs(adds), curs(0), upper_bound(0)
{
    array = new uint32_t[maxs];
    findPrimes();
}

Primes::Primes(uint32_t max) : maxs(adds), curs(0), upper_bound(max)
{
    array = new uint32_t[maxs];
    findPrimes();
}

Primes::Iterator Primes::begin()
{
        Primes::Iterator it;
        return it;
}

Primes::Iterator Primes::end()
{
    Iterator it;
    if (upper_bound != 0 || array == nullptr)
    {
        it.value = array + sizeof(uint32_t) * curs;
        return it;
    }
    else
    {
        throw -2;
    }
}

uint32_t Primes::size()
{
    return curs;
}

uint32_t Primes::operator[](uint32_t index)
{
    if (upper_bound == 0 && index > maxs)
    {
        continueFindPrimes(index);
    }
    return array[index];
}

void Primes::reinitArray()
{
    maxs *=2;
    uint32_t *a = new uint32_t[maxs];
    memcpy(a, array, sizeof(uint32_t) * curs);
    delete[] array;
    array = a;
}

void Primes::findPrimes()
{
    if (upper_bound > 0)
    {
        uint32_t j = 0;
        for(uint32_t i = 2; i <= upper_bound; ++i)
        {
            if (curs == maxs)
            {
                reinitArray();
            }
            if (i == 2)
            {
                array[curs] = i;
                ++curs;
                continue;
            }
            else if (i > 10 && ((i % 2 == 0) || (i % 10 == 5)))
            {
                continue;
            }
            for (j = 0; array[j] > static_cast<uint32_t>(sqrt(i) + 1); ++j)
            {

                if (i % array[j] == 0)
                {
                    break;
                }
            }
            if (i % array[j] != 0)
            {
                array[curs] = i;
                ++curs;
            }
        }
    }
    else
    {
        uint32_t j = 0;
        for(uint32_t i = 2; curs < maxs; ++i)
        {
            if (i == 2)
            {
                array[curs] = i;
                ++curs;
                continue;
            }
            else if (i > 10 && ((i % 2 == 0) || (i % 10 == 5)))
            {
                continue;
            }
            for (j = 0; array[j] > static_cast<uint32_t>(sqrt(i) + 1); ++j)
            {

                if (i % array[j] == 0)
                {
                    break;
                }
            }
            if (i % array[j] != 0)
            {
                array[curs] = i;
                ++curs;
            }
        }
    }
}

void Primes::continueFindPrimes(uint32_t index)
{
    while (index > maxs)
    {
        reinitArray();
        uint32_t j = 0;
        for(uint32_t i = array[curs-1]; curs < maxs; ++i)
        {
            if (curs == maxs)
            {
                reinitArray();
            }
            if (i == 2)
            {
                array[curs] = i;
                ++curs;
                continue;
            }
            else if (i > 10 && ((i % 2 == 0) || (i % 10 == 5)))
            {
                continue;
            }
            for (j = 0; array[j] > static_cast<uint32_t>(sqrt(i) + 1); ++j)
            {

                if (i % array[j] == 0)
                {
                    break;
                }
            }
            if (i % array[j] != 0)
            {
                array[curs] = i;
                ++curs;
            }
        }
    }
}

uint32_t Primes::Iterator::operator*()
{
    return *value;
}

Primes::Iterator &Primes::Iterator::operator=(Primes::Iterator &it)
{
    this->value = it.value;
    return *this;
}

const Primes::Iterator& operator++(Primes::Iterator& it)
{
    it.value += sizeof (it.value);
	return it;
}

const Primes::Iterator& operator--(Primes::Iterator& it)
{
    it.value -= sizeof (it.value);
	return it;
}


