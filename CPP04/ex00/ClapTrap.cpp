/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:30:50 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/30 13:44:17 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10),
 _attackDamage(0) {
	std::cout << GREEN << "ClapTrap default constructor called." 
	<< RESET <<std::endl; 
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), 
_energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap name constructor called." 
	<< RESET <<std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), 
_hitPoints(other._hitPoints), _energyPoints(other._energyPoints), 
_attackDamage(other._attackDamage) {
	std::cout << GREEN << "ClapTrap copy constructor called." 
	<< RESET <<std::endl; 
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	std::cout << GREEN << "ClapTrap copy assignment operator called." 
	<< RESET <<std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called." 
	<< RESET <<std::endl;
}


void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << YELLOW << "ClapTrap " << _name << " attacks " 
		<< target << " causing " << _attackDamage << 
		" points of damage!" << RESET << std::endl;
		if (_energyPoints != 0)
			_energyPoints--;
	}
	if (_hitPoints == 0)
		std::cout << "Someone killed ClapTrap " << _name << 
		". ClapTrap " << _name << " can't attack anymore."<< std::endl;
	if (_energyPoints <= 0) 
		std::cout << "Claptrap " << _name << 
		" is too exhausted to attack (not enough _energyPoints)!" << std:: endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has " <<_hitPoints << " _hitPoints." << std::endl 
	<< "ClapTrap " << _name << " takes " << amount << 
	" damage points." << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
		std::cout << RED << "ClapTrap " << _name << " is dead." 
		<< RESET << std::endl;
	}
	else {
		std::cout << GREEN << "ClapTrap " << _name << " is still alive. Amount of _hitPoints: " 
		<< _hitPoints << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints > 0)
	{
		std::cout << ITALIC << "ClapTrap " << _name << " before beeing repaired by " 
		<< amount << ":\n" << RESET << YELLOW << 
		"_energyPoints: " << _energyPoints << "\n" << 
		"_hitPoints: " << _hitPoints << RESET << std::endl;
		
		_hitPoints += amount; 
		--_energyPoints;
		
		std::cout << ITALIC << "ClapTrap " << _name << " after beeing repaired by " 
		<< amount << ":\n" << RESET << GREEN << 
		"_energyPoints: " << _energyPoints << "\n" << 
		"_hitPoints: " << _hitPoints << RESET << std::endl;
	}
	if (_energyPoints <= 0)
		std::cout << RED << "Not enough _energyPoints to repair the ClapTrap." 
		<< RESET << std::endl;
}


