/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:13:28 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/09 13:00:46 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

typedef void (Harl::*FuncPtr)();

void	Harl::debug()
{
	std::cout << BLUE << "I love having extra bacon for my \n\
7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
	<< RESET << std::endl;
}

void	Harl::info()
{
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger! If you did, \
I wouldn’t be asking for more!\n"
	<< RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years, whereas you started working here just last month.\n"
	<< RESET << std::endl;
}

void	Harl::error()
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now.\n"
	<< RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	FuncPtr funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
