#include "PmergeMe.hpp"


void PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string token = argv[i];
		
		//check all digit
		for(std::string::size_type j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(token[j]))
				throwError("Not a number", token);
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

void throwError(const std::string& msg, const std::string& token) {
	std::ostringstream oss;
	oss << RED << msg << ": '" << token << "'" << RESET;
	throw std::runtime_error(oss.str());
}




