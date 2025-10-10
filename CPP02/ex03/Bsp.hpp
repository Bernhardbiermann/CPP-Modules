/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:51:43 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/20 15:52:52 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
#define BSP_HPP

#include "Point.hpp"

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif