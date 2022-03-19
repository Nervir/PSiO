#include <iostream>
#include <string>

std::string replace(std::string sentence, std::string old_word, std::string new_word) {

	while (sentence.find(old_word) != std::string::npos) {
		sentence = sentence.substr(0, sentence.find(old_word)) + new_word + sentence.substr(sentence.find(old_word) + size(old_word), size(sentence));
	}

	return sentence;
}


int main()
{
	std::string input = "John has a dog, dog ate John!";
	std::string output = replace(input, "dog", "tiger");

	std::cout << output;
}