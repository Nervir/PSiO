#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string sentence) {
	std::vector<std::string> words;

	while (sentence.find(' ') != std::string::npos) {
		std::string temp = sentence.substr(0, sentence.find(' '));
		sentence.erase(0, sentence.find(' ') + 1);
		words.push_back(temp);
	}
	words.push_back(sentence);

	return words;
}

std::vector<std::string> split(std::string sentence, char character) {
	std::vector<std::string> words;

	while (sentence.find(character) != std::string::npos) {
		std::string temp = sentence.substr(0, sentence.find(character));
		sentence.erase(0, sentence.find(character) + 1);
		words.push_back(temp);
	}
	words.push_back(sentence);

	return words;
}


int main()
{
	std::string sentence = "Ala ma kota";
	std::vector<std::string> words = split(sentence); // wynik: {"Ala", "ma", "kota"}

	std::string csv = "Mount Everest,8848,1953";
	std::vector<std::string> data = split(csv, ','); // wynik: {"Mount Everest", "8848", "1953"}
	
	for (std::string i : words)
		std::cout << i << ' ';
	std::cout << std::endl;
	for (std::string i : data)
		std::cout << i << ' ';
	std::cout << std::endl;
}