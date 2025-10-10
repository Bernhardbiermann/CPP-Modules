#ifndef EASYFINDER_HPP
# define EASYFINDER_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"


// Cant use .size() because some containers are not working with size (e.g. lists)
//.begin() and .end() works with all the containers. 
/*template <typename T>
typename T::iterator easyfind(T& container, int value){
	for (typename T::iterator it = container.begin(); it != container.end(); ++it){
		if (*it == value){
			return it;
		}
	}
	std::cerr << "Value not found!" << std::endl;
	return 0;
};*/

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}


#endif