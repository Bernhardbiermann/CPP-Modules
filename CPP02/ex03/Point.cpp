/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:03:55 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/20 15:45:25 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return(*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed	Point::getY() const
{
	return this->_y;
}