#include <iostream>

using namespace std;

uint64_t factorial_r(int number) {
	if (number > 1) {
		return factorial_r(number - 1) * number;
	} 
	else {
		return 1;
	}
}

int main()
{
	uint64_t result = factorial_r(15);
	cout << result << endl; // wynik: 1307674368000
}