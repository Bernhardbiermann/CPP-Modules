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

/*
| Funktion     | Beschreibung                                            |
| ------------ | ------------------------------------------------------- |
| `size()`     | Gibt die Anzahl der Elemente zurück                     |
| `empty()`    | Gibt `true` zurück, wenn leer                           |
| `clear()`    | Entfernt alle Elemente                                  |
| `front()`    | Zugriff auf das erste Element                           |
| `back()`     | Zugriff auf das letzte Element                          |
| `at(index)`  | Zugriff mit Bereichsprüfung (wirft Ausnahme bei Fehler) |
| `operator[]` | Zugriff ohne Bereichsprüfung                            |

| Funktion                  | Beschreibung                                     |
| ------------------------- | ------------------------------------------------ |
| `push_back(value)`        | Fügt ein Element **am Ende** hinzu               |
| `pop_back()`              | Entfernt das **letzte** Element                  |
| `push_front(value)`       | Fügt ein Element **am Anfang** hinzu             |
| `pop_front()`             | Entfernt das **erste** Element                   |
| `insert(iterator, value)` | Fügt an beliebiger Position ein                  |
| `erase(iterator)`         | Entfernt Element an Position                     |
| `erase(first, last)`      | Entfernt Bereich von Elementen                   |
| `assign(count, value)`    | Füllt den Container mit mehreren gleichen Werten |
| `swap(otherDeque)`        | Tauscht den Inhalt mit einem anderen `deque`     |
*/


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
			RPNstack.push_back(std::atoi(token.c_str()));
		if (isOperator(token[0]))
		{
			it = RPNstack.end();
			--it;
			if (it == RPNstack.begin())
			{
				oss << RED "Not enough numbers on the stack" << RESET;
				throw std::runtime_error(oss.str());
			}
			int last = RPNstack.back();
			RPNstack.pop_back();
			int beforeLast = RPNstack.back();
			RPNstack.pop_back();
			if (token[0] == '+')
				RPNstack.push_back(beforeLast + last);
			else if (token[0] == '-')
				RPNstack.push_back(beforeLast - last);
			else if (token[0] == '*')
				RPNstack.push_back(beforeLast* last);
			else if (token[0] == '/')
			{
				if (last == 0)
					throw std::runtime_error("Division by zero! Yikes!");
				RPNstack.push_back(beforeLast / last);
			}
		}
	}
	if (RPNstack.size() != 1)
	{
		oss << RED "Too many numbers for all the operators!" << RESET;
		throw std::runtime_error(oss.str());
	}
	int calculated = RPNstack.back();
	std::cout << GREEN << calculated << RESET << std::endl;
};