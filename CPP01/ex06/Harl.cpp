/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:13:28 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/16 16:41:30 by bbierman         ###   ########.fr       */
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

int	Harl::getLevelIndex(std::string &level)
{
	if (level == "DEBUG")
		return 0;
	else if (level == "INFO")
		return 1;
	else if (level == "WARNING")
		return 2;
	else if (level == "ERROR")
		return 3;
	else
		return 4;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*FuncPtr)();
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	FuncPtr funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	int index = getLevelIndex(level);
	
	switch	(index)
	{
	case 0:
		std::cout << BLUE << "DEBUG:" << RESET << std::endl;
		(this->*funcs[0])();
	case 1:
		std::cout << GREEN << "INFO:" << RESET << std::endl;
		(this->*funcs[1])();
	case 2:
		std::cout << YELLOW << "WARNING:" << RESET << std::endl;
		(this->*funcs[2])();
	case 3:
		std::cout << RED << "ERROR:" << RESET << std::endl;
		(this->*funcs[3])();
		break;
	case 4:
		std::cout << "DEFAULT:" << std::endl;
		std::cout << ITALIC << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
		break;
	}
}
