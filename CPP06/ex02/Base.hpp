/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:41:33 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/28 19:08:08 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib> // rand()
#include <ctime> // time()
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PURPLE	"\033[35m"
#define CYAN	"\033[36m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Base {
	public:
		virtual ~Base();
};

// It randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base * generate(void);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p);
//  Using a pointer inside this function is forbidden.
void identify(Base& p);

#endif