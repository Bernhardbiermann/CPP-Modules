/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:07:34 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/12 16:11:55 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"
#include <string>
#include <iostream>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanA {
	private:
		std::string name;
		Weapon* weapon;
	
	public:
		HumanA(std::string newName, Weapon& newWeapon);
		void	setWeapon(Weapon &newWeapon);
		void	attack();
};

#endif