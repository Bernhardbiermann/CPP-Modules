#include "BitcoinExchange.hpp"
#include <map>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "It has to be exactly 2 arguments :(\n";
		return 1;
	}
	BtcEx::isDatabaseValid(argv[1]);
};