/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:03:55 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/18 15:47:08 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _number(0)
{
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	this->_number = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_number = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_number;
}

void	Fixed::setRawBits(int const newNumber)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = newNumber;
}