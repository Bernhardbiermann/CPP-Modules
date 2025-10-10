/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:19:54 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 16:11:51 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed_frag_name") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap default constructor called." 
	<< RESET <<std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap name constructor called." 
	<< RESET <<std::endl; 
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << GREEN << "FragTrap copy constructor called." 
	<< RESET <<std::endl; 
}

FragTrap&	FragTrap::operator=(const FragTrap &other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << GREEN << "FragTrap copy assignement constructor called." 
	<< RESET <<std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called." 
	<< RESET <<std::endl;
}


void	FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << YELLOW << "FragTrap " << _name << " attacks " 
		<< target << " causing " << _attackDamage << 
		" points of damage!" << RESET << std::endl;
		if (_energyPoints != 0)
			_energyPoints--;
	}
	if (_hitPoints == 0)
		std::cout << "Someone killed FragTrap " << _name << 
		". FragTrap " << _name << " can't attack anymore."<< std::endl;
	if (_energyPoints <= 0) 
		std::cout << "Fragtrap " << _name << 
		" is too exhausted to attack (not enough _energyPoints)!" << std:: endl;
}

void	FragTrap::highFivesGuys(){
	std::cout << BLUE << "FragTrap " << _name << 
	" smiles and requests a positive high five!✋" << RESET << std::endl;
}
