#include <iostream>
#include <string>
#include <vector>

std::string find_longest_word(std::string sentence) {
	std::vector<std::string> words;

	while (sentence.find(' ') != std::string::npos) {
		std::string temp = sentence.substr(0, sentence.find(' '));
		sentence.erase(0, sentence.find(' ') + 1);
		words.push_back(temp);
	}
	words.push_back(sentence);

	std::string longest_word = words[0];

	for (int i = 0; i < size(words); i++) {
		if (size(longest_word) < size(words[i])) {
			longest_word = words[i];
		}
	}
	return longest_word;
}

int main()
{
	std::string input = "Ala ma kota kot jezdzi na Roombie";

	std::string longest = find_longest_word(input); // "Roombie"
	std::cout << longest;
}