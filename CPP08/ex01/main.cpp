#include "Span.hpp"
#include <iostream>
#include <string>
#include <ctime>

int main() {
	std::cout << GREEN << "=== STANDARD TEST ===\n";
	try {
		Span x = Span(5);
		x.addNumber(11);
		x.addNumber(2);
		x.addNumber(15);
		x.addNumber(42);
		x.addNumber(3);
		std::cout << "Biggy: " << x.longestSpan() << "\nShorty: " << x.shortestSpan() << RESET << "\n" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
		
	std::cout << RED << "=== EXCEPTION TEST ===\n";
	try {
		Span x = Span(3);
		x.addNumber(11);
		x.addNumber(2);
		x.addNumber(15);
		x.addNumber(42);
		std::cout << "Biggy: " << x.longestSpan() << "\nShorty: " << x.shortestSpan() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n" << std::endl;
	}

	std::cout << YELLOW << "=== ALMOST INFINITE NUMBERS TEST ===\n";
	try {
		Span x(10000);
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++) {
			x.addNumber(std::rand());
		}
		std::cout << "Biggy: " << x.longestSpan() << "\nShorty: " << x.shortestSpan() << RESET << "\n" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
