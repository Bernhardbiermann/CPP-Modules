/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:03 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/11 15:15:18 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Wrong amount of arguments!" << std::endl;
		return (0);
	}
	if (!std::atoi(argv[1]) || std::atoi(argv[1]) <= 0)
	{
		std::cout << "Invalid amount of zombies" << std::endl;
		return (0);
	}
	int n = std::atoi(argv[1]);
	std::string name = argv[2];
	Zombie* horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
	{
		std::cout << BLUE << i + 1<< " " << RESET;
		horde[i].announce();
	}
	delete[] horde;
}