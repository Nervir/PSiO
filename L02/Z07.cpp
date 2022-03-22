#include <iostream>
#include <vector>

int binary_search(const int& number, const std::vector<int> &list) {
	int list_start = 0;
	int list_end = list.size() - 1;
	while (list_start <= list_end) {
		int index = list_start + ((list_end - list_start) / 2);
		if (number == list[index]) {
			return index;
		}
		else if (number < list[index]) {
			list_end = index - 1;
		}
		else if (number > list[index]) {
			list_start = index + 1;
		}
	}
	return -1;
}

int main()
{
	std::vector<int> list = { 1, 2, 5, 8, 9, 11, 15 };
	int number = 15;
	std::cout << binary_search(number, list) << std::endl;
}