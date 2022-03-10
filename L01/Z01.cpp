#include <iostream>
#include <vector>

using namespace std;

void fill_progressive(vector<int>& vec) {
    for (int i = 0; i < size(vec); i++) {
        vec[i] = i + 1;
    }
}

void print_vector(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << ", ";
    }
}


int main()
{
    vector<int> vec(6);
    fill_progressive(vec);
    print_vector(vec);
}