#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main( void ) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::list<int> lst;
	lst.push_front(1);
	lst.push_front(4);
	lst.push_front(3);

	std::deque<int> deque;
	lst.push_front(42);
	lst.push_front(44);
	lst.push_front(43);

	try {
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 1);
		std::cout << "Found in vector: " << *it <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(deque, 44);
		std::cout << "Found in deque-vector: " << *it <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 4);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}