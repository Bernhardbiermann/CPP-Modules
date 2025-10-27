#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cctype>
#include <limits>
#include <string>
#include <vector>
#include <deque>


#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

#define DEBUG false

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> deq;

	public:
		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& oth);
		PmergeMe& operator=(const PmergeMe& oth);
		~PmergeMe();

		void parseInput(int argc, char** argv);
		void setAndMeasure();

		template <typename Container>
		void	printContainer(const Container &c, size_t limit) const;

	private:
		template <typename Container>
		void	mergeInsertionSort(Container &c);


};

#endif