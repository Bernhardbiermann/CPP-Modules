#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stack>
#include <limits>
#include <string>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

/*

container: stack
1) Check single digits numbers operators
2) Calculate
3) close
*/

class RPN {
	private:
		// VARIABLES /////////////////////////////////////
		std::stack<int>	RPNstack;

		// HELPER ////////////////////////////////////////
		bool	isOperator(char c);
		bool	isDigit(char c);

	public:
		// CONSTRUCTORS /////////////////////////////////
		RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN& other);
		~RPN();

		// METHODS //////////////////////////////////////
		void	processInput(const std::string& input);
};

#endif