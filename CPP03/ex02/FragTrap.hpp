/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:19:38 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 16:11:32 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class FragTrap : public ClapTrap {
	public:
		/* Default constructor*/
		FragTrap();
		/* Name constructor */
		FragTrap(std::string name);
		/* Copy Constructor */
		FragTrap(const FragTrap &other);
		/* Copy assignement constructor*/
		FragTrap &operator=(const FragTrap &other);
		/* Destructor */
		~FragTrap();

		void	highFivesGuys();
		void	attack(const std::string& target);
};

#endif