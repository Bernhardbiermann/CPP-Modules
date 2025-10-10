/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:03:44 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/18 15:47:43 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Fixed {
	private:
		int					_number;
		static const int	_fractionalBits = 8;

	public:
		/* Default constructor */
		Fixed();
		/* Copy constructor */
		Fixed(const Fixed &other);
		/* Copy assignment operator */
		Fixed &operator=(const Fixed &other);
		/* Destructor */
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const newNumber);
};

#endif
