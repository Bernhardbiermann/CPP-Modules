/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:02:30 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 16:11:11 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class ScavTrap : public ClapTrap {
	public:
		/* Default constructor*/
		ScavTrap();
		/* Name constructor */
		ScavTrap(std::string name);
		/* Copy Constructor */
		ScavTrap(const ScavTrap &other);
		/* Copy assignement constructor*/
		ScavTrap &operator=(const ScavTrap &other);
		/* Destructor */
		~ScavTrap();

		void	guardGate();
		void	attack(const std::string& target);
};

#endif