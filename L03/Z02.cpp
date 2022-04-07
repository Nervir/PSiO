#include <algorithm>
#include <iostream>
#include <list>
#include <random>
#include <ctime>

int randomInt(int min, int max) {
    static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}
void print(std::list<int> l) {
    for (int number : l) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    const int n = 10;
    std::list<int> numbers(n);
    std::generate(numbers.begin(), numbers.end(), []() { return randomInt(-20, 20); });;

    //for (int i = 0; i < numbers.size(); i++) {
    //    std::cout << numbers[i] << ", ";
    //}

    print(numbers);

    int to_find = 15;
    //std::erase(numbers, to_find); //https://en.cppreference.com/w/cpp/container/list/erase2

    numbers.remove(to_find);
    
    print(numbers);
}