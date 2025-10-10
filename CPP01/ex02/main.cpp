/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:03 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/02 14:43:40 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>


int main()
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "The memory address of the string variable: " << &brain << std::endl
		<< "The memory address held by stringPTR: " << stringPTR << std::endl
		<< "The memory address held by stringREF: " << &stringREF << std::endl
		<< std::endl;

	std::cout << "The value of the string variable: " << brain << std::endl
		<< "The value pointed to by stringPTR: " << *stringPTR << std::endl
		<< "The value pointed to by stringREF: " << stringREF << std::endl;
}