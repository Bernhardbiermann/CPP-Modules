#include "iter.hpp"

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& x) {
	std::cout << x << " ";
}

void doubleInt(int& x) {
	x *= 2;
}

void toUpper(std::string& s) {
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = std::toupper(s[i]);
}

int main() {
	std::cout << "=== INT TEST ===\n";
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, printElement<int>);
	std::cout << "\n-> multiply by 2\n";
	iter(arr, 5, doubleInt);
	iter(arr, 5, printElement<int>);
	std::cout << "\n\n";

	std::cout << "=== STRING TEST ===\n";
	std::string names[] = {"bob", "alice", "charlie"};
	iter(names, 3, printElement<std::string>);
	std::cout << "\n-> uppercase\n";
	iter(names, 3, toUpper);
	iter(names, 3, printElement<std::string>);
	std::cout << "\n\n";

	std::cout << "=== CONST TEST ===\n";
	const float piVals[] = {3.14f, 2.71f, 1.41f};
	iter(piVals, 3, printElement<float>);
	std::cout << "\n";

	return 0;
}
