/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:03 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/16 16:38:40 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	Harl harl;
	
	if (argc >= 3)
	{
		std::cout << "Too many arguments!";
		return 1;
	}
	if (argc <= 1)
	{
		std::cout << "Too few arguments!";
		return 1;
	}
	std::string input = argv[1];
	harl.complain(input);
	return 0;
}
