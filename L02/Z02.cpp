#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all(std::string sentence, char character) {
	std::vector<size_t> index;
	size_t found = sentence.find(character, 0);
	while (found != std::string::npos) {
		index.push_back(found);
		found = sentence.find(character, found+1);
	}
	return index;
}

int main()
{
	std::string input = "Ala ma kota";

	std::vector<size_t> pos = find_all(input, 'a'); // wynik: {2, 5, 10}
	for (int i = 0; i < pos.size(); i++) {
		std::cout << pos[i] << std::endl;
	}
}