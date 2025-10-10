/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:44:51 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/09 10:53:27 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <string>
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Zombie {
	private:
		std::string	name;
		
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif