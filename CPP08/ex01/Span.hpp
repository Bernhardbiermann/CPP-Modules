#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <stdexcept>
#include <limits>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Span {
	protected:
		unsigned int		max;
		std::vector<int>	numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& b);
		Span &operator=(const Span& b);
		~Span();

		void		addNumber(int x);
		void		addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int			shortestSpan();
		unsigned int			longestSpan();

		class spanIsFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Can't add number: Span is full!";
				}
		};

		class notEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers!";
				}
		};

		class tooManyNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Too many numbers!";
				}
		};
};

#endif