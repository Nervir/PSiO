#include <iostream>
#include <cstring>

bool is_palindrome(std::string word) {
    for (int i = 0; i < size(word); i++) {
        word[i] = tolower(word[i]);
    }
    for (int i = 0; i < size(word) / 2 + 1; i++) {
        if (word[i] != word[size(word) - i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string word = "Racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }
}
