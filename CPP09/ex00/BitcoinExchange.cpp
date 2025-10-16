#include "BitcoinExchange.hpp"

// CONSTRUCTOR /////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange() : btcExchangeTable() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : btcExchangeTable(other.btcExchangeTable) {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		btcExchangeTable = other.btcExchangeTable;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};


// HELPER //////////////////////////////////////////////////////////////////////

std::string	BitcoinExchange::trimWhitespace(const std::string &line)
{
	std::string result = line;
	size_t start = 0;
	size_t end = result.size();
	
	while (start < result.size() && std::isspace(result[start]))
		start++;
	while (end > start && std::isspace(result[end -1]))
		end--;
	return result.substr(start, end - start);
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	int year, month, day;
	int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	
	if (month < 1 || month > 12)
		return false;

	if (year < 2009 || year > 2022)
		return false;
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	
	return true;
}

int	BitcoinExchange::isValidValue(const std::string& input)
{
	if (input.empty())
		return -1;
	std::istringstream iss(input);
	double val;
	iss >> val;
	if (iss.fail() || !iss.eof())
		return -1;
	if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
		return -1;
	if (input == "-0")
		return -2;
	if (val < 0)
		return -2;
	if (val > 1000)
		return -3;
	return 0;
}

bool	BitcoinExchange::checkHeader(const std::string& input)
{
	std::string line, date, value;
	size_t	posDelim;

	line = input;
	line = trimWhitespace(input);
	posDelim = line.find('|');
	if (posDelim == std::string::npos) 
		return false;
	date = trimWhitespace(line.substr(0, posDelim));
	if (date != "date")
		return false;
	value = trimWhitespace(line.substr(posDelim + 1));
	if (value != "value")
		return false;
	return true;
}

float	BitcoinExchange::getExchangerate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it;

	if (btcExchangeTable.empty())
		throw std::runtime_error("Exchange table is empty");
	it = btcExchangeTable.find(date);
	if (it != btcExchangeTable.end())
		return it->second;
	it = btcExchangeTable.lower_bound(date);
	if (it == btcExchangeTable.begin())
		throw std::runtime_error("No earlier date available");
	it--;
	return it->second;
}

// METHODS /////////////////////////////////////////////////////////////////////

void	BitcoinExchange::loadDataBase(const std::string& filename)
{	int	lineCount = 1;
	std::ostringstream oss;
	std::ifstream infile(filename.c_str());
	std::string line, date, btcValue;
	size_t posDelim;
	
	if (!infile)
	{
		oss << "Error: could not open file: " << filename;
		throw std::runtime_error(oss.str());
	}
	getline(infile, line);
	line = trimWhitespace(line);
	if (line != "date,exchange_rate")
	{
		oss << "Error: checking header failed: " << filename;
		throw std::runtime_error(oss.str());
	}
	while (getline(infile, line)) 
	{
		oss.str("");
		lineCount++;
		if (line.empty()) //skip empty line
			continue;
		line = trimWhitespace(line);
		posDelim = line.find(',');
		if (posDelim == std::string::npos)
		{
			oss << "Missing comma in line " << lineCount << ": " << line;
			throw std::runtime_error(oss.str());
		}
		date = trimWhitespace(line.substr(0, posDelim));
		btcValue = trimWhitespace(line.substr(posDelim + 1));

		if (!isValidDate(date))
		{
			oss << "Invalid date in line " << lineCount <<  "\nOriginal Line: " << line;
			throw std::runtime_error(oss.str());
		}
		int validValue = isValidValue(btcValue);
		if (validValue != 0 && validValue != -3)
		{
			oss << "Invalid value in line " << lineCount <<  "\nOriginal Line: " << line << " date: " << date << " value: " << btcValue;
			throw std::runtime_error(oss.str());
		}
		if (btcExchangeTable.find(date) != btcExchangeTable.end())
		{
			oss << "Duplicate entries in line " << lineCount << ": " << line;
			throw std::runtime_error(oss.str());
		}
		btcExchangeTable[date] = std::atof(btcValue.c_str());
	}
};

void	BitcoinExchange::processInput(const std::string &filename) 
{
	int	lineCount = 1;
	std::ostringstream oss;
	std::ifstream infile(filename.c_str());
	std::string line, date, btcAmount;
	size_t posDelim;
	float Exchangerate;
	float fBtcAmount;
	
	if (!infile)
	{
		oss << "Error: could not open file: " << filename;
		throw std::runtime_error(oss.str());
	}
	while (getline(infile, line))
	{
		if (!line.empty()) //skip empty line
			break;
	}
	if (!checkHeader(line))
	{
		oss << "Error: checking header failed: " << filename;
		throw std::runtime_error(oss.str());
	}
	while (getline(infile, line)) 
	{
		oss.str(""); // reset the stringstream
		lineCount++;
		oss << lineCount;
		if (line.empty()) //skip empty line
			continue;
		line = trimWhitespace(line);

		posDelim = line.find('|');
		if (posDelim == std::string::npos || posDelim == 0 || posDelim == line.size() - 1)
		{
			std::cout << RED "Error: wrong position/missing '|'\n" RESET;
			continue;
		}

		date = trimWhitespace(line.substr(0, posDelim));
		btcAmount = trimWhitespace(line.substr(posDelim + 1));

		if (!isValidDate(date))
		{
			std::cout << RED "Error: bad input => " << date << "\n" RESET;
			continue; 	
		}
		int valStatus = isValidValue(btcAmount);
		if (valStatus == -1)
		{
			std::cout << RED "Error: bad input => " << btcAmount << "\n" RESET;
			continue;
		}
		if (valStatus == -2)
		{
			std::cout << RED "Error: not a postiv number: " << btcAmount << "\n" RESET;
			continue;
		}
		if (valStatus == -3)
		{
			std::cout << RED "Error: too large a number: " << btcAmount << "\n" RESET;
			continue;
		}
		char* end;
		fBtcAmount = std::strtod(btcAmount.c_str(), &end);
		Exchangerate = getExchangerate(date);
		std::cout << GREEN << date << " => " << btcAmount << " = " << Exchangerate * fBtcAmount << "\n" RESET;
	}
};