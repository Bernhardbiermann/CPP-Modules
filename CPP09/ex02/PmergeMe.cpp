#include "PmergeMe.hpp"


// CONSTRUCTOR & DESTRUCTOR ////////////////////////////////////////////////////

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int argc, char** argv) {
	parseInput(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe& oth) : vec(oth.vec), deq(oth.deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& oth) {
	if (this != &oth){
		vec = oth.vec;
		deq = oth.deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

// METHODS /////////////////////////////////////////////////////////////////////

void PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string token = argv[i];
		
		//check all digit
		for(std::string::size_type j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(token[j]))
				throwError("Not a valid input", token);
		}
		//check limits
		long value = std::atol(token.c_str());
		if (value <= 0 || value > std::numeric_limits<int>::max())
			throwError("Number out of bounds", token);
			
		//check duplicate
		if (std::find(vec.begin(), vec.end(), value) != vec.end())
			throwError("Duplicate value", token);

		vec.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
	std::cout << "Printing the vec[input]: " << std::endl;
	printContainer(vec, 10);
	std::cout << "Printing the deq[input]: " << std::endl;
	printContainer(deq, 10);
}

void PmergeMe::takeTimeStempAndStartSorting() 
{
	std::cout << "Before: ";
	printContainer(vec, 10);

	clock_t startVec = clock();
	//mergeInsertionSort(vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	//mergeInsertionSort(deq);
	clock_t endDeq = clock();

	std::cout << "After: ";
	printContainer(vec, 10);

	double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with " GREEN << "std::vector" RESET ": " << timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size()
			  << " elements with " GREEN << "std::deque" RESET ": " << timeDeq << " us" << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertionsSort(const Container &c, int blockSize) 
{
	int	numberCount = c.size();
	int groupSize = blocksize / 2;
	if (blockSize < numberCount)
	{
		recursionCount--;
		return;
	}
	for (int i = 0; i + blockSize < numberCount; i += blockSize)
	{
		int group1_first = i;
		int group1_last = group1_first + groupSize - 1;
		int group2_first = group1_last + 1;
		int group2_last = group2_first + groupSize - 1;

		comparisonCount++;

		if (numbers[group1_last] > numbers[group2_last])
		{
			for (int j = 0: j < groupSize; j++) 
				std::swap(numbers[a_first + j], numbers[b_first + j]);
		}
	}
	mergeInsertionSort(blockSize * 2);

	// create a new numbersList
	Container newNumbersList;
	int addedBs = 0;

	// add B0 to newNumberslist
	newNumberslist.insert(newNumbersList.end(), numbers.begin(), numbers.begin() + groupSize);
	addedBs++;

	// add all the As
	for (int i = 0; i + groupSize - 1 < numberCount; i+= groupSize)
	{
		if ((i / groupSize) % 2 == 1)
			newNumberslist.insert(newNumbersList.end(), numbers.begin() + i, numbers.begin() + i + groupSize);
	}

}

template <typename Container>
void PmergeMe::printContainer(const Container &c, size_t limit) const 
{
	typename Container::const_iterator it = c.begin();
	size_t count = 0;
	while (it != c.end() && count < limit)
	{
		std::cout << *it << " ";
		++it;
		++count;
	}
	if (it != c.end())	
		std::cout << "[...]";
	std::cout << std::endl;
}


// HELPER /////////////////////////////////////////////////////////////////////

void PmergeMe::throwError(const std::string& msg, const std::string& token) {
	std::ostringstream oss;
	oss << RED << msg << ": '" << token << "'" << RESET;
	throw std::runtime_error(oss.str());
}

template <typename Container>
bool isSorted(const Container &numbers)
{
	for (typename Container::const_iterator it = numbers.begin(); it + 1 != numbers.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}




