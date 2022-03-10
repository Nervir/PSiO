#include <iostream>

using namespace std;

uint64_t factorial(int number) {
	uint64_t result = 1;
	while (number > 0) {
		result *= number;
		number--;
	}
	return result;
}

int main()
{
	uint64_t result = factorial(15);
	cout << result << endl; // wynik: 1307674368000
}