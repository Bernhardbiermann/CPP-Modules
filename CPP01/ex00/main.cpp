/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:28:43 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/11 12:21:15 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Test 1: Stack zombie in main\n"
		<< "Expected: Constructor msg, announcement, no destructor msg\n";
	Zombie Hans("Hallo");
	Hans.announce();
	std::cout << "\n\n";

	std::cout << "Test 2: Stack zombie function\n"
		<< "Expected: Constructor msg, announcement, destructor msg\n";
	randomChump("Gallo");
	std::cout << "\n\n";

	std::cout << "Test 3: Heap Zombie"
		<< "Expected: Constructor msg, announcement, pause, destructor msg\n";
	Zombie* HalloGallo = newZombie("HalloGallo");
	HalloGallo->announce();
	std::cout << "\npause\n\n";
	delete HalloGallo;
}

