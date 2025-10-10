/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:48:46 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/11 17:23:32 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string newWeapon)
{
	type = newWeapon;
}


const std::string	Weapon::getType()
{ 
	return (type);
}

void	Weapon::setType(const std::string newType)
{
	type = newType;
}