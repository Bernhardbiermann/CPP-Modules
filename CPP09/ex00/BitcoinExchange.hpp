#ifndef EASYFINDER_HPP
# define EASYFINDER_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>

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

class BtcEx {
	private:
		std::map<std::string, float>	btcExchangeTable;


	public:
		BtcEx();
		BtcEx(const BtcEx& other);
		BtcEx &operator=(const BtcEx& other);
		~BtcEx();

	void	loadDataBase(const std::string& filename){
		std::ifstream infile(filename.c_str());
		std::string line;
		bool header = false;
		
		if (!infile)
			throw std::runtime_error("Opening infile failed!");
		getline(infile, line);
		line.split();
		if (!(line == "date,exchange_rate"))
			throw std::runtime_error("Checking header failed!");
		while (getline(infile, line)) 
		{
			std::string year = input.substr(0, input.length());
			std::string "-" = input.substr(0, input.length());
			std::string month = input.substr(0, input.length());
			std::string "-" = input.substr(0, input.length());
			std::string day = input.substr(0, input.length());
			std::string "|" = input.substr(0, input.length());
			std::string btcValue = input.substr(0, input.length());
		}
	};



	bool	isDatabaseValid() const;
	bool	hasDate(const std::string &date) const;
	void	processInput(const std::string &inputfile);
	float	getRateForDate(const std::string &date) const;
	void	displayResult(const std::string &date, float amount, float value);
};




#endif