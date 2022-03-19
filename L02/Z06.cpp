#include <iostream>
#include <vector>

int main()
{
    std::vector<int> list = { 10, 15, 23, 8, 5, 9, 40, 11, 12, 13, 1 };
    int list_size = list.size();
    bool change;
    do {
        change = false;
        for (int i = 0; i < list_size - 1; i++) {
            if (list[i] > list[i + 1]) {
                int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
                change = true;
            }
        }
    } while (change == true);
    for (auto i : list) {
        std::cout << i << ", ";
    }
}