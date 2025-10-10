/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:27:03 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/20 16:20:05 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "Bsp.hpp"
#include <iostream>
#include <cmath>

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);
	Point inside(2.5f, 2.0f);
	Point edge(2.5f, 0.0f);
	Point outside(5.0f, 5.0f);

	std::cout << std::boolalpha;
	std::cout << "Inside:  " << bsp(a, b, c, inside) << std::endl;  // true
	std::cout << "Edge:    " << bsp(a, b, c, edge) << std::endl;    // false
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl; // false
}