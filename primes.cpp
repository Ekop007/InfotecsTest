#include "primes.hpp"

Primes::Primes() : s(0), endf(false)
{
    array = nullptr;
}

Primes::Primes(uint32_t max) : s(max), endf(true)
{
    array = new uint32_t[s];
}

Primes::Iterator Primes::begin()
{
        Primes::Iterator it;
        return it;
}

Primes::Iterator Primes::end()
{
    Iterator it;
    if (endf || array == nullptr)
    {
        it.value = array + sizeof(uint32_t) * s;
    }
}

uint32_t Primes::size()
{
    return s;
}

uint32_t Primes::operator[](uint32_t index)
{
    return array[index];
}

uint32_t Primes::Iterator::operator*()
{
        return *value;
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


