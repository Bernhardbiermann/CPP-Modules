#include "Array.hpp"

#include <iostream>
#include <string>

int main() {
	std::cout << "=== INT ARRAY ===\n";
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << " ";
	std::cout << "\n\n";

	std::cout << "=== STRING ARRAY ===\n";
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "template";
	words[2] = "world";

	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n\n";

	std::cout << "=== COPY CONSTRUCTOR ===\n";
	Array<std::string> copy(words);
	copy[1] = "copied";
	std::cout << "Original: \n";
		for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << " ";
	std::cout << "\n";

	std::cout << "Copy:     \n";
		for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << "\n\n";

	std::cout << "=== ASSIGNMENT OPERATOR ===\nCreating an empty new one (other):\n";
	Array<int> other;
	for (unsigned int i = 0; i < other.size(); ++i)
		other[i] = i * 10;

	for (unsigned int i = 0; i < other.size(); ++i)
		std::cout << other[i] << " ";

	other = numbers;
	std::cout << "\nAfter assignement to numbers (other = numbers):\n";
	for (unsigned int i = 0; i < other.size(); ++i)
		other[i] = i * 10;

	for (unsigned int i = 0; i < other.size(); ++i)
		std::cout << other[i] << " ";
	std::cout << "\n\n";

	std::cout << "=== OUT OF BOUNDS TEST ===\n";
	try {
		std::cout << numbers[42] << "\n";
	} catch (std::exception &e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}
