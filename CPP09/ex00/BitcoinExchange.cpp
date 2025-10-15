#include "BitcoinExchange.hpp"

Btc::Btc();


// HELPER //////////////////////////////////////////////////

std::string	BtcEx::trimWhitespace(const std::string &line)
{
	std::string result = line;
	size_t start = 0;
	size_t end = result.size();
	
	if (result.empty())
		return result;
	while (start < result.size() && std::isspace(result[start]))
		start++;
	while (end > start && std::isspace(result[end -1]))
		end--;
	return result.substr(start, end - start);
}

bool	BtcEx::isValidDate(const std::string &date)
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

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	
	return true;
}

bool	BtcEx::isValidValue(const std::string& input)
{
	if (input.empty())
		return false;
	std::istringstream iss(input);
	float val = 0;
	iss >> val;
	if (iss.fail() || !iss.eof())
		return false;
	if (val < 0 || val > 1000)
		return false;
	return true;
}

std::string	BtcEx::trimWhitespace(const std::string &line)
{
	std::string result = line;
	size_t start = 0;
	size_t end = result.size();
	
	if (result.empty())
		return result;
	while (start < result.size() && std::isspace(result[start]))
		start++;
	while (end > start && std::isspace(result[end -1]))
		end--;
	return result = result.substr(start, end - start);
}

// METHODS ///////////////////////////////////////////////////////

void	BtcEx::loadDataBase(const std::string& filename)
{	int	lineCount = 1;
	std::ostringstream oss;
	std::ifstream infile(filename.c_str());
	std::string line, date, btcValue;
	size_t posCom;
	
	if (!infile)
		throw std::runtime_error("Opening infile failed!");
	getline(infile, line);
	line = trimWhitespace(line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Checking header failed!");
	while (getline(infile, line)) 
	{
		lineCount++;
		if (line.empty()) //skip empty line
			continue;
		line = trimWhitespace(line);
		posCom = line.find(',');
		if (posCom == std::string::npos){
			oss << "Missing comma in line " << lineCount << ": " << line;
			throw std::runtime_error(oss.str());
		}
		date = trimWhitespace(line.substr(0, posCom));
		btcValue = trimWhitespace(line.substr(posCom + 1));

		if (!isValidDate(date))
		{
			oss << "Invalid date in line " << lineCount <<  "\nOriginal Line: " << line;
			throw std::runtime_error(oss.str());
		}
		if (!isValidValue(btcValue))
		{
			oss << "Invalid value in line " << lineCount <<  "\nOriginal Line: " << line;
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