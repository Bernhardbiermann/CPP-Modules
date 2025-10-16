#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "It has to be exactly 2 arguments :(\n";
		return 1;
	}

	RPN rpn;
	
	try {
			rpn.processInput(argv[1]);
	} catch (std::exception &e) {
			std::cerr << RED << e.what() << '\n' << RESET;
		}
};