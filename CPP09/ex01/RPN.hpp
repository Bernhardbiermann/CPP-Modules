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

container: deque

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

1) Check single digits numbers and mathematical operators
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
		RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN& other);
		~RPN();

		// METHODS //////////////////////////////////////
		void	processInput(const std::string& input);
};

#endif