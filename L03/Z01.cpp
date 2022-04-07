#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}

int main()
{
	const int n = 10;
	std::vector<int> numbers(n);
	std::generate(numbers.begin(), numbers.end(), []() { return randomInt(-20, 20); });

	for (int number : numbers) {
		std::cout << number << ", ";
	}

	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << ", ";
	}

	int to_find = 15;
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		if (*it == to_find) {
			numbers.erase(it);
		}
	}
}