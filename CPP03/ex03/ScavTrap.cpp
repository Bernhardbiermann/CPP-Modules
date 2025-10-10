/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:02:22 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/30 13:45:02 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap default constructor called." 
	<< RESET <<std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap name constructor called." 
	<< RESET <<std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << GREEN << "ScavTrap copy constructor called." 
	<< RESET <<std::endl; 
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << GREEN << "ClpaTrap copy assignment operator called." 
	<< RESET <<std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called." 
	<< RESET <<std::endl;
}


void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << YELLOW << "ScavTrap " << _name << " attacks " 
		<< target << " causing " << _attackDamage << 
		" points of damage!" << RESET << std::endl;
		if (_energyPoints != 0)
			_energyPoints--;
	}
	if (_hitPoints == 0)
		std::cout << "Someone killed ScavTrap " << _name << 
		". ScavTrap " << _name << " can't attack anymore."<< std::endl;
	if (_energyPoints <= 0) 
		std::cout << "Scavtrap " << _name << 
		" is too exhausted to attack (not enough _energyPoints)!" << std:: endl;
}

void	ScavTrap::guardGate(){
	std::cout << BLUE << "ScavTrap " << _name << " has entered Gate Keeper mode." << RESET << std::endl;
}
