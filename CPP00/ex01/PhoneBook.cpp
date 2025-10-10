/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:59:01 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/07 14:02:37 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

PhoneBook::PhoneBook() : i(0), nbr_contacts(0) {}
		
std::string	PhoneBook::read_line(std::string prompt)
{
	std::string	line;

	std::cout << prompt;
	while (true)
	{
		if (!std::getline(std::cin, line))
			return "";
		if (!line.empty())
			break;
		std::cout << "Invalid input. PLease try again.\n";
	}
	return line;
}

std::string	PhoneBook::get_nbr(std::string prompt)
{
	std::string	line;
	bool	numbers = true;
	
	std::cout << prompt;
	while (true)
	{
		if (!std::getline(std::cin, line))
			return "";
		if (!line.empty())
		{
			numbers = true;
			for (unsigned long k = 0; k < line.length(); k++)
			{
				if (!std::isdigit((unsigned char)line[k]))
					numbers = false;
			}
			if (numbers == true)
				break ;
			std::cout << "Invalid input. Please enter digits only\n";
			continue ;
		}
		//std::cout << "Invalid input. Please enter digits only\n";
	}
	return line;
}

void	PhoneBook::add()
{
	std::string	first, last, nick, phone, secret;
	first = read_line("\nFirst name: ");
	last = read_line("Last name: ");
	nick = read_line("Nickname: ");
	phone = get_nbr("Phone number: ");
	secret = read_line("Let me ask something personal: What is your darkest secret? \n");
	std::cout << std::endl;
	contacts[i].overwrite(first, last, nick, phone, secret);
	if (nbr_contacts < 8)
		nbr_contacts++;
	i++;
	if (i >= 8)
		i = 0;
}
	
void	PhoneBook::fill()
{
	std::string	hallo = "Hallo", gallo = "Gallo", phone = "12345";
	for (int k = 0; k < 8; k++)
		contacts[k].overwrite(hallo, gallo, hallo, phone, gallo);
	nbr_contacts = 8;
	i = 0;
}

std::string	PhoneBook::truncate_string(std::string str)
{
	int	len = str.length();
	if (len <= 10)
		str.insert(0, 10 - len, ' ');
	if (len > 10)
	{
		str = str.substr(0,9);
		str.append(1, '.');
	}
	return str;
}
	
void	PhoneBook::print_phonebook()
{
	std::string	str;
	std::cout << "\n|    Index|First name| Last name|  Nickname|\n";
	for (int j = 0; j < nbr_contacts; j++)
	{
		std::cout << "|        " << j << "|";
		str = truncate_string(contacts[j].get_first());
		std::cout << str << "|";
		str = truncate_string(contacts[j].get_last());
		std::cout << str << "|";
		str = truncate_string(contacts[j].get_nick());
		std::cout << str << "|\n";
	}
}

void	PhoneBook::print_contact()
{
	if (nbr_contacts == 0)
	{
		std::cout << "There are no phonebook entries. :(\n";
		return ;
	}
	int j = -1;
	std::string	nbr;
	while (true)
	{
		nbr = get_nbr("\nPlease enter a valid index to view a phonebook entry: \n");
		j = std::atoi(nbr.c_str());
		if (j < nbr_contacts && j > -1)
			break ;
	}
	std::cout << "\nFirst name: " << contacts[j].get_first() << "\n";
	std::cout << "Last name: " << contacts[j].get_last() << "\n";
	std::cout << "Nickname: " << contacts[j].get_nick() << "\n";
	std::cout << "Phone number: " << contacts[j].get_phone() << "\n";
	std::cout << "Darkest secret: " << contacts[j].get_secret() << "\n\n";
}

bool	PhoneBook::empty()
{
	if (nbr_contacts < 1)
		return true;
	return false;
}