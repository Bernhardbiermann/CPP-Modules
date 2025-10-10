#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"


// Funktioniert nur mit definierten Variablen
template <typename T> // Template Instanziierung
void swap (T& a, T& b){
	T tmp = a;
	a = b;
	b = tmp;
}

// Funktioniert auch mit literals --> sogar mit int const &z = min(3, 4), weil const vom compilier verortet wird: geht nicht ohne const:
template <typename T>
T const& min (const T &a, const T &b){
	return (b <= a) ? b : a;
}

// const T & == T const & == Referenz auf eine Konstante - Richtig
// T& const == eine konstante Referenz - Referenz immer konstant daher hier falsch
template <typename T>
T const& max (const T &a, const T &b){ 
	return (b >= a) ? b : a;
}

#endif