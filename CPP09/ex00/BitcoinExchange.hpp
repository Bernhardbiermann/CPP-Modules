#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <limits>
#include <string>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

/*

container: map
commands:
	insert({k,v}) 	- Insert key-value pair
	erase(key) 		- Remove element by key
	clear() 		- Remove all elements
	find(key) 		- Find element by key

Access:
	operator[] 	- Access or insert element
	at(key)		- Access with bounds checking
	size() 		- Number of elements
	empty() 	- Check if empty

1) BitcoinExchange-Tabelle in einen map-container einlesen
2) Input-Error-Check
3) Wert zu bestimmten Datum auslesen
4) Gesamtwert bestimmen
5) Darstellen
6) Sauber schliessen
*/

class BitcoinExchange {
	private:
		// VARIABLES /////////////////////////////////////
		std::map<std::string, float>	btcExchangeTable;

		// HELPER ////////////////////////////////////////
		std::string	trimWhitespace(const std::string &line);
		int		isValidValue(const std::string& input);
		bool	isValidDate(const std::string &date);
		bool	checkHeader(const std::string& input);
		float	getExchangerate(const std::string& date) const;


	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		// METHODS //////////////////////////////////////
		void	loadDataBase(const std::string& filename);
		void	processInput(const std::string& filename);
};

#endif