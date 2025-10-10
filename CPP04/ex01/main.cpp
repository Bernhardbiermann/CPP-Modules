/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:05 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 14:31:13 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Gretel;
	ScavTrap Hans("Hans");
	Gretel.attack("Hexe");
	Hans.attack("Wurst");
	Hans.takeDamage(5);
	Hans.beRepaired(3);
	Hans.takeDamage(30);
	std::cout << ITALIC << "Someone screams: YOU WANT SOME MORE?" << RESET << std::endl;
	Hans.takeDamage(30);
	Hans.attack("Wurst");
	Hans.guardGate();
	return (0);
}