#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Usage: ./PmergeMe <positive_numbers>\n" RESET;
		return 1;
	}
	
	PmergeMe algo;

	try 
	{
		algo.parseInput(argc, argv);
		algo.printContainer(std::vector<int> vec, 10);
		algo.parseContainer(std::deque<int> vec, 10);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << '\n' << RESET;
		return 1;
	}
	return 0;
};