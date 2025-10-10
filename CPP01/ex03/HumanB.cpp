/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:41:29 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/12 16:14:14 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &newName) : name(newName), weapon(NULL) {}


void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl; 
	else
		std::cout << name << "has no weapon to attack." << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}