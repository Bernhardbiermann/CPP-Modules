/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:45:22 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/28 19:27:54 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
	return ;
};

Base*	generate() {
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
};

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << BLUE "A\n" RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN "B\n" RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << PURPLE "C\n" RESET;
};

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE "A\n" RESET;
	} catch (const std::exception& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << GREEN "B\n" RESET;
		} catch (const std::exception& e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << PURPLE "C\n" RESET;
			} catch (const std::exception& e) {
				try {
					std::cout << RED "=\n" RESET;
				} catch (const std::exception& e) {}
			}
		}
	}
};