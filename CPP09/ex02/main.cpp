#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Usage: ./PmergeMe <positive_numbers>\n" RESET;
		return 1;
	}

	try 
	{
		PmergeMe<std::vector<int> >	vec(argc, argv);
		PmergeMe<std::deque<int> >	deq(argc, argv);

		std::cout << BLUE "\n--- Using std::vector ---\n" RESET;
		vec.takeTimeStempAndStartSorting();

		std::cout << BLUE "\n--- Using std::deque ---\n" RESET;
		deq.takeTimeStempAndStartSorting();

	} catch (std::exception &e) {
		std::cerr << RED << e.what() << '\n' << RESET;
		return 1;
	}
	return 0;
};