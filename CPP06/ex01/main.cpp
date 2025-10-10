/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:31:24 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/28 18:27:00 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cmath>

int main() {
	Data original = {._name = "School", ._value = 42};

	uintptr_t raw = Serializer::serialize(&original);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Original address   : " << &original << "\n";
	std::cout << "Deserialized address: " << deserialized << "\n";

	if (deserialized == &original)
		std::cout << GREEN "Success: Pointer matches!\n" RESET;
	else
		std::cout << RED "Failure: Pointer mismatch!\n" RESET;

	std::cout << "Deserialized data:\n";
	std::cout << "Value: " << deserialized->_value << ", Name: " << deserialized->_name << "\n";
}