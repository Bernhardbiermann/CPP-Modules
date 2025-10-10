/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:44:25 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/09 11:06:09 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

#include <string>
#include <iostream>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Weapon {
	private:
		std::string type;
	
	public:
		const std::string	getType();
		void	setType(std::string type);
		Weapon(const std::string newWeapon);
};

#endif
