
// CONSTRUCTOR, OPERATOR & DESTRUCTOR //////////////////////////////////////////

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char** argv) {
	parseInput(argc, argv);
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& oth) : numbers(oth.numbers) {}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& oth) {
	if (this != &oth){
		numbers = oth.numbers;
	}
	return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

// METHODS /////////////////////////////////////////////////////////////////////

template <typename T>
void PmergeMe<T>::parseInput(int argc, char** argv)
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
		if (value < 0 || value > std::numeric_limits<int>::max())
			throwError("Number out of bounds", token);
			
		//check duplicate
		if (std::find(numbers.begin(), numbers.end(), value) != numbers.end())
			throwError("Duplicate value", token);

		numbers.push_back(static_cast<int>(value));
	}
}

template <typename T>
void PmergeMe<T>::takeTimeStempAndStartSorting(std::string type)
{
	std::cout << "Before: ";
	printContainer(numbers);

	clock_t start = clock();
	mergeInsertionSort(numbers);
	clock_t end = clock();

	std::cout << "After: ";
	printContainer(numbers);

	double time = double(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << numbers.size()
			  << " elements with " GREEN << type << RESET ": " << time << " us" << std::endl;
}

template <typename T>
void PmergeMe<T>::mergeInsertionSort(T& numbers) 
{
	size_t	numberCount = numbers.size();
	if (numberCount <= 1)
		return ;
	// init
	T bigNum;
	T smallNum;
	// compare and split min/max
	for (size_t i = 0; i + 1 < numberCount; i += 2)
	{
		int a = numbers[i];
		int b = numbers[i + 1];
		if (a < b) {
			smallNum.push_back(a);
			bigNum.push_back(b);
		} else {
			bigNum.push_back(a);
			smallNum.push_back(b);
		}
	}
	// if odd numbers: add the last one to smallNum
	if (numberCount % 2)
		smallNum.push_back(numbers[numberCount - 1]);

	// sort the big ones recursively
	mergeInsertionSort(bigNum);

	// add small[]
	T result;
	result.push_back(bigNum[0]);

	std::vector<size_t> jac = genJacobsthal(smallNum.size());
	T insert;

	// insert smallNums in result
	for (size_t i = 0; i < jac.size(); i++)
	{
		size_t idx = jac[i];
		if (idx > smallNum.size())
			break;
		binaryInsert(result, smallNum[idx - 1]);
		insert.push_back(idx - 1);	
	}

	// insert remaining smallNums
	for (int i = 0; i < (int)smallNum.size(); i++)
	{ 
		bool inserted = false;
		for (size_t j = 0; j < insert.size(); j++)
		{
			if (insert[j] == i)
				inserted = true;
		}
		if (!inserted)
			binaryInsert(result, smallNum[i - 1]);
	}

	numbers = result;
}

// HELPER /////////////////////////////////////////////////////////////////////

template <typename T>
void PmergeMe<T>::throwError(const std::string& msg, const std::string& token) 
{
	std::ostringstream oss;
	oss << RED << msg << ": '" << token << "'" << RESET;
	throw std::runtime_error(oss.str());
}

template <typename T>
bool PmergeMe<T>::isSorted(const T& numbers)
{
	for (typename T::const_iterator it = numbers.begin(); it + 1 != numbers.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}	

template <typename T>
void PmergeMe<T>::printContainer(const T& c) const 
{
	typename T::const_iterator it = c.begin();
	while (it != c.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

// Jacobsthal sequence generator
template <typename T>
std::vector<size_t> PmergeMe<T>::genJacobsthal(size_t n)
{
	std::vector<size_t> seq;
	if (n == 0)
		return seq;
	seq.push_back(1);
	size_t a = 1, b = 1, next;
	while ((next = a + 2 * b) <= n)
	{
		seq.push_back(next);
		a = b;
		b = next;
	}
	return seq;
}

// Binary insert helper
template <typename T>
void PmergeMe<T>::binaryInsert(T& container, int value)
{
	typename T::iterator it = std::lower_bound(container.begin(), container.end(), value);
	container.insert(it, value);
}


