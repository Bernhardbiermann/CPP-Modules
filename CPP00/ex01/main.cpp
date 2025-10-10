/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:03:09 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/07 12:04:02 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //for std::cout, std::cerr
#include <string>
#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	std::string	input;
	PhoneBook	pb;
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Too many arguments. Please try again!\n";
		return (1);
	}
	std::cout << "Hello, here is your phonebook:\n";
	while (true)
	{
		std::cout <<"Please enter ADD, SEARCH or EXIT.\n> ";
		if (!std::getline(std::cin, input))
			break;	
		if (input == "ADD")
			pb.add();
		else if (input == "FILL")
			pb.fill();
		else if (input == "SEARCH")
		{
			pb.print_phonebook();
			pb.print_contact();
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Unknown command. Please try again!\n";
	}
	std::cout <<"Thank you for using the awesome phonebook. Have a good day :)\n";
	return (0);
}