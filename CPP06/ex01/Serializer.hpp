/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:09 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/28 18:25:50 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Serializer {
	private:
		// constructor
		Serializer();
		// copy constructor
		Serializer(const Serializer& other);
		// copy assignement constructor
		Serializer &operator=(const Serializer& other);
		// destructor
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif