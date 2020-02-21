class Primes
{
public:
	Primes(uint32_t max); // контейнер прочтых чисел в диапазоне 1...max
	Primes(); //контейнер простых чисел без верхней границы
	class Iterator
	{
	public:
		uint32_t const operator*();
	private:
		uint32_t *value;
	}
	Iterator begin();
	Iterator end(); // для контейнера без верхней границы end() достижим только в пустом контейнере
	uint32_t size();
	uint32_t operator[](uint32_t index);
private:
	uint32_t *array;
	uint32_t s;
	uint32_t
}

friend const Primes::Iterator& operator++(Primes::Iterator& it);
friend const Primes::Iterator& operator--(Primes::Iterator& it);
friend const bool operator==(const Primes::Iterator& it1, const Primes::Iterator& it2);
friend const bool operator!=(const Primes::Iterator& it1, const Primes::Iterator& it2);

