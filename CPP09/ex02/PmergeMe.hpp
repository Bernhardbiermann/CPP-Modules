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

template <typename T>
class PmergeMe {
	private:
		T	numbers;

		int numberCount;
		int recursionCount;

	public:
		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& oth);
		PmergeMe& operator=(const PmergeMe& oth);
		~PmergeMe();

		void	parseInput(int argc, char** argv);
		void	takeTimeStempAndStartSorting();
		void	printContainer(const T& c, size_t limit) const;

	private:
		void	mergeInsertionSort(T& numbers);

	// HELPER /////////////////////////////////////////////////////////////////
	void throwError(const std::string& msg, const std::string& token);
	bool isSorted(const T& numbers);
	bool printContainer(const T& c) const;
	std::vector<size_t> genJacobsthal(size_t n);
	void binaryInsert(T& c, int value);
};

# include "PmergeMe.tpp"

#endif
