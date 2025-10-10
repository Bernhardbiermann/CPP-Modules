/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:12:53 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/12 16:20:06 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"
#include <string>
#include <iostream>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	
	public:
		HumanB(const std::string &newName);
		void	setWeapon(Weapon &newWeapon);
		void	attack();
};

#endif