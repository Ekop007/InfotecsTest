#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <cstdint>

static const uint32_t adds = 20;

class Primes
{
public:
	Primes(uint32_t max); // контейнер прочтых чисел в диапазоне 1...max
	Primes(); //контейнер простых чисел без верхней границы
	class Iterator
	{
	public:
        uint32_t operator*();

        friend const Iterator& operator++(Primes::Iterator& it);
        friend const Iterator& operator--(Primes::Iterator& it);
        Iterator& operator=(Primes::Iterator& it);

        friend class Primes;
	private:
		uint32_t *value;
    };
	Iterator begin();
	Iterator end(); // для контейнера без верхней границы end() достижим только в пустом контейнере
	uint32_t size();
	uint32_t operator[](uint32_t index);

private:

    void reinitArray();
    void findPrimes();
    void continueFindPrimes(uint32_t index);

	uint32_t *array;
    uint32_t maxs;
    uint32_t curs;
    uint32_t upper_bound;
};

#endif // PRIMES_HPP
