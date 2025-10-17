#include "RPN.hpp"

// CONSTRUCTOR /////////////////////////////////////////////////////////////////

RPN::RPN() : RPNstack() {};

RPN::RPN(const RPN& other) : RPNstack(other.RPNstack) {};

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		RPNstack = other.RPNstack;
	}
	return *this;
}

RPN::~RPN() {};

// HELPER //////////////////////////////////////////////////////////////////////

bool	RPN::isOperator(char c) 
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
};

bool	RPN::isDigit(char c) 
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
};


// METHODS /////////////////////////////////////////////////////////////////////

void	RPN::processInput(const std::string& input)
{
	std::ostringstream oss;
	std::istringstream iss(input);
	std::string token;
	std::deque<int>::const_iterator it;

	while (iss >> token)
	{
		oss.str("");
		if (token.size() != 1)
		{
			oss << RED "Not a single digit number or an operator: '" << token << "'" << RESET;
			throw std::runtime_error(oss.str());
		}
		if (isDigit(token[0]))
			RPNstack.push(std::atoi(token.c_str()));
		if (isOperator(token[0]))
		{
			if (RPNstack.size() < 2)
			{
				oss << RED "Not enough numbers on the stack" << RESET;
				throw std::runtime_error(oss.str());
			}
			int last = RPNstack.top();
			RPNstack.pop();
			int beforeLast = RPNstack.top();
			RPNstack.pop();
			if (token[0] == '+')
				RPNstack.push(beforeLast + last);
			else if (token[0] == '-')
				RPNstack.push(beforeLast - last);
			else if (token[0] == '*')
				RPNstack.push(beforeLast* last);
			else if (token[0] == '/')
			{
				if (last == 0)
					throw std::runtime_error("Division by zero! Yikes!");
				RPNstack.push(beforeLast / last);
			}
		}
	}
	if (RPNstack.size() != 1)
	{
		oss << RED "Too many numbers for all the operators!" << RESET;
		throw std::runtime_error(oss.str());
	}
	int calculated = RPNstack.top();
	std::cout << GREEN << calculated << RESET << std::endl;
};