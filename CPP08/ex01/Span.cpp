#include "Span.hpp"

Span::Span() : max(0), numbers(0) {};
Span::Span(unsigned int N) : max(N), numbers(0) {};
Span::Span(const Span& b) : max(b.max), numbers(b.numbers){};
Span& Span::operator=(const Span& b){
	if (this != &b)
	{
		max = b.max;
		numbers = b.numbers;
	}
	return *this;
};
Span::~Span() {};

void	Span::addNumber(int x){
	if (numbers.size() >= max)
		throw spanIsFullException();
	numbers.push_back(x);
	return;
};

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; begin != end; ++it){
		if (numbers.size() >= max)
			throw spanIsFullException();
		numbers.push_back(*it);
	}
};

unsigned int	Span::shortestSpan() {
	if (numbers.size() < 2)
		throw notEnoughNumbersException();
	std::vector<int> sortedList = numbers;
	std::sort(sortedList.begin(), sortedList.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	//std::cout << "Min span: " << minSpan << std::endl;
	for (size_t i = 0; i < sortedList.size() - 1; ++i) {
		unsigned int diff = sortedList[i + 1] - sortedList[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
};

unsigned int	Span::longestSpan() {
	if (numbers.size() < 2)
		throw notEnoughNumbersException();
	unsigned int maxSpan = *std::max_element(numbers.begin(), numbers.end()) - 
              *std::min_element(numbers.begin(), numbers.end());
	return maxSpan;
};

