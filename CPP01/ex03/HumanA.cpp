/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:41:29 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/12 16:11:35 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string newName, Weapon &newWeapon) : name(newName), weapon(&newWeapon) {}


void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl; 
}

void	HumanA::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}