#include <iostream>
#include <vector>
#include <tuple>

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
    cout << endl;
}

//void print_vector(const vector<int>& vec) {
//    for (int i = 0; i < size(vec); i++) {
//        if (i == size(vec) - 1) {
//            cout << vec[i];
//            continue;
//        }
//        cout << vec[i] << ", ";
//    }
//    cout << endl;
//}

tuple<double, double> min_max(vector<double>& vec, double &min, double &max) {
    min, max = vec[0];

    for (double i : vec) {
        if (min > i) {
            min = i;
        }
        if (max < i) {
            max = i;
        }
    }
    return make_tuple(min, max);
}

int main()
{
    vector<int> vec(6);
    fill_progressive(vec);
    print_vector(vec);

    double min;
    double max;
    //double min = 0;
    //double max = 0;
    vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
    min_max(values, min, max);

    cout << min << ", " << max;
}