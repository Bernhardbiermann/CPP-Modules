/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:20:17 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 12:24:09 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class ClapTrap {
	protected:
		std::string		_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

	public:
		/* Default constructor*/
		ClapTrap();
		/* Name constructor */
		ClapTrap(std::string name);
		/* Copy Constructor */
		ClapTrap(const ClapTrap &other);
		/* Copy assignement constructor*/
		ClapTrap &operator=(const ClapTrap &other);
		/* Destructor */
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif