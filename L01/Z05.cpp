#include <iostream>

using namespace std;

bool is_prime(int number) {
    if (number == 0 || number == 1) {
        return false;
    }
    for (int i = 1; i < (number / 2) + 1; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int prime_or_not_prime = 112;
    if (is_prime(prime_or_not_prime)) {
        cout << prime_or_not_prime << " is prime!" << endl;
    }
    else {
        cout << prime_or_not_prime << " is not prime!" << endl;
    }
}
