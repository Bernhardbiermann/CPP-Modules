#include "MutantStack.hpp"

#include <iostream>
#include <string>
#include <list>

int main()
{
	//MutantStack<int> mstack;
	std::list<int>		mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::list<int>::iterator last = mstack.end();
	--last;
	std::cout << *last << std::endl;0
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	std::list<int>::reverse_iterator rit = mstack.rbegin();
	std::list<int>::reverse_iterator rite = mstack.rend();
	++it;
	--it;
	std::cout << "=== ITERATOR ===" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "=== REVERSE_ITERATOR ===" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	//std::stack<int> s(mstack);
	return 0;
}

