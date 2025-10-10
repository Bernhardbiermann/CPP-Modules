/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:05:05 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/23 16:30:18 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap Hans("Hans");
	Hans.attack("42");
	Hans.whoAmI();
	Hans.takeDamage(30);
	Hans.beRepaired(20);
	return (0);
}