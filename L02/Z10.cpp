#include <iostream>
#include <vector>


std::vector<double> get_poly(int n);
double poly(double x, std::vector<double> p);
std::vector<double> zero(double x_min, double x_max, std::vector<double> p, double step);
double zero_r(double bottom, double top, std::vector<double> p);


int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << std::endl;
    std::vector<double> p = get_poly(n);

    double x_min, x_max, step;
    x_min = -0.5;
    x_max = 1.5;
    step = 0.1;
    std::vector<double> zeros = zero(x_min, x_max, p, step);
    double x1;
    for (int i = 0; i < zeros.size(); i++) {
        std::cout << zeros[i] << std::endl;
    }
}


std::vector<double> get_poly(int n) {
    std::vector<double> polynomial(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the coefficient of x^" << i << ": ";
        std::cin >> polynomial[i];
        std::cout << std::endl;
    }
    return polynomial;
}


double poly(double x, std::vector<double> p) {
    double y = 0;
    for (int i = 0; i < p.size(); i++) {
        y += p[i] * pow(x, i);
    }
    return y;
}


std::vector<double> zero(double x_min, double x_max, std::vector<double> p, double step) {
    std::vector<double> zeros;
    double x1, x2;
    for (double x = x_min; x <= x_max; x += step) {
        x1 = x;
        if (x + step <= x_max) {
            x2 = x + step;
        }
        else {
            x2 = x_max;
        }
        if (poly(x1, p) * poly(x2, p) < 0) {
            zeros.emplace_back(zero_r(x1, x2, p));
        }
    }
    return zeros;
}


double zero_r(double bottom, double top, std::vector<double> p) {

    double middle = ((top - bottom) / 2) + bottom;
    double m_result = poly(middle, p);

    if (top - bottom < 1e-9) {
        return middle;
    }

    double t_result = poly(top, p);
    double b_result = poly(bottom, p);
    if (b_result * m_result < 0) {
        return zero_r(b_result, m_result, p);
    }
    if (m_result * t_result < 0) {
        return zero_r(m_result, t_result, p);
    }
}