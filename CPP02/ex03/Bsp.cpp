/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:53:00 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/20 16:27:59 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();
	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();
	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	float result = std::fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5f);
	return Fixed(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = area(a, b, c);
	Fixed p1 = area(point, b, c);
	Fixed p2 = area(a, point, c);
	Fixed p3 = area(a, b, point);

	if (p1 == 0 || p2 == 0 || p3 == 0)
		return false;

	return (total == p1 + p2 + p3);
}