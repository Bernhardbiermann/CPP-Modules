/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:37:18 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 16:15:53 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
		/* Default constructor*/
		DiamondTrap();
		/* Name constructor */
		DiamondTrap(std::string name);
		/* Copy Constructor */
		DiamondTrap(const DiamondTrap &other);
		/* Copy assignement constructor*/
		DiamondTrap &operator=(const DiamondTrap &other);
		/* Destructor */
		~DiamondTrap();

		void	whoAmI();
		void	attack(const std::string& target);
};

#endif