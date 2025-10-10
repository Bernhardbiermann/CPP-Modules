/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:03 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/16 14:58:26 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <stdlib.h>

int	main()
{
	Harl harl;
	
	std::cout << BLUE << "DEBUG:" << RESET << std::endl;
	harl.complain("DEBUG");
	
	std::cout << GREEN << "INFO:" << RESET << std::endl;
	harl.complain("INFO");
	
	std::cout << YELLOW << "WARNING:" << RESET << std::endl;
	harl.complain("WARNING");
	
	std::cout << RED << "ERROR:" << RESET << std::endl;
	harl.complain("ERROR");
	
	std::cout << "SOMETHING ELSE:" << std::endl;
	harl.complain("SOMETHINGELSE");

	return 0;
}
