#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <gtest/gtest.h>
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
        Iterator& operator+=(uint32_t num);
        Iterator& operator-=(uint32_t num);
        Iterator& operator-(uint32_t num);
        uint32_t operator-(Primes::Iterator& it);
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

class TestPrimes : public ::testing::Test
{
protected:
    Primes *primes;
};

TEST_F(TestPrimes, testEnd)
{
    primes = new Primes();
    auto t = primes->end();
    ASSERT_EQ(nullptr, t);
}

TEST_F(TestPrimes, upperBoundTest)
{
    primes = new Primes(5);
    auto t = primes->end();
    --t;
    ASSERT_EQ(11, *t);
}

TEST_F(TestPrimes, infinityArrayTest)
{
    primes = new Primes();
    auto t = primes[79];
    ASSERT_EQ(409, t);
}

TEST_F(TestPrimes, sizeTest)
{
    primes = new Primes(50);
    auto t = primes->size();
    ASSERT_EQ(50, t);
}


#endif // PRIMES_HPP
