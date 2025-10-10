/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:05 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 14:29:31 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Gretel;
	ClapTrap Hans("Hans");
	Gretel.attack("Hexe");
	Hans.attack("Wurst");
	Hans.takeDamage(5);
	Hans.beRepaired(3);
	Hans.takeDamage(30);
	std::cout << "Someone screams: YOU WANT SOME MORE?" << std::endl;	
	Hans.takeDamage(30);
	return (0);
}