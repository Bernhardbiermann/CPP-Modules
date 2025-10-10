/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:28:58 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/20 15:32:30 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		/* Default constructor */
		Point();
		/* Int constructor */
		Point(const float x, const float y);
		/* Copy constructor*/
		Point(const Point &other);
		/* Copy assignment operator */
		Point &operator=(const Point &other);
		/* Destructor */
		~Point();

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif