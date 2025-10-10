/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:37:12 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/30 13:44:52 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
	: ClapTrap("unnamed_clap_trap"), _name("unnamed_diamond_trap_name") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << GREEN << "DiamondTrap default constructor called." 
	<< RESET <<std::endl; 
}

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << GREEN << "DiamondTrap name constructor called." 
	<< RESET <<std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
	ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name){
	std::cout << GREEN << "DiamondTrap copy constructor called." 
	<< RESET <<std::endl; 
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << GREEN << "DiamondTrap copy assignment operator called." 
	<< RESET <<std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called." 
	<< RESET <<std::endl;
}


void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout << BLUE << "My name ist " << _name << 
	" and my grandparent (clap_trap_name) is " << getClapName()
	<< "!" << RESET << std::endl;
}


