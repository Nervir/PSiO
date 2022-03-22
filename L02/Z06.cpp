#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& list) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < list.size() - 1; i++) {
            if (list[i] > list[i + 1]) {
                int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
                change = true;
            }
        }
    } while (change == true);
}


int main()
{
    std::vector<int> list = { 10, 15, 23, 8, 5, 9, 40, 11, 12, 13, 1 };
    bubble_sort(list);
    for (auto i : list) {
        std::cout << i << ", ";
    }
}