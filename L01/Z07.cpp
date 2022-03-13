#include <iostream>

void draw_square(int size, bool left_diagonal, bool right_diagonal) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y == 0) {
                std::cout << '#';
                continue;
            }
            if (x == 0 || x == size - 1) {
                std::cout << '#';
                continue;
            }
            if (y == size - 1) {
                std::cout << '#';
                continue;
            }
            if (left_diagonal) {
                if (y == x) {
                    std::cout << '#';
                    continue;
                }
            }
            if (right_diagonal) {
                if (y == x - size + 2 * y + 1) {
                    std::cout << '#';
                    continue;
                }
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    draw_square(60, true, true);
}