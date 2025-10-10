/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:44:51 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/09 10:50:36 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <string>
#include <iostream>

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
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif