#include <iostream>
#include <cstdlib>
#include<cmath>
#define M_PI
using namespace std;

double pi_leibniz(double stop_at) {
    double number = 1;
    int i = 0;
    double pi = 0;
    do {
        pi = pi + pow(-1, i) * 1/number;
        number += 2;
        i++;
    } while (1 / number >= stop_at);
    return pi*4;
}

int main()
{
    double stop_at = 0.0001;
    double pi_approx = pi_leibniz(stop_at);

    std::cout << pi_approx << std::endl;
    std::cout << "error: " << pi_approx - M_PI;
}