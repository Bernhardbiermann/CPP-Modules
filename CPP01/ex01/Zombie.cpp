/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:29:10 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/11 15:16:19 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {}

void	Zombie::announce()
{
	std::cout << GREEN << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::Zombie(std::string given_name)
{
	name = given_name;
	std::cout << YELLOW << "Constructor called for Zombie " << name << RESET <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << "Destructor called for Zombie " << name << RESET << std::endl;
}

void	Zombie::setName(std::string newName)
{
	name = newName;
}


