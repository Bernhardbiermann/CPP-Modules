#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <stack>
#include <deque>


template <typename T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack() {};
	MutantStack(const MutantStack& b) : std::stack<T>(b) {};
	MutantStack &operator=(const MutantStack &b) {
		std::stack<T>::operator=(b);
		return *this;
	}
	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;


	iterator begin() { return this->c.begin(); };
	iterator end() {return this->c.end();};

	reverse_iterator rbegin() { return this->c.rbegin(); };
	reverse_iterator rend() {return this->c.rend();};

};

#endif