/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:09 by bbierman          #+#    #+#             */
/*   Updated: 2025/09/09 10:08:56 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <string>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class ScalarConverter {
	private:
		// constructor
		ScalarConverter();
		// copy constructor
		ScalarConverter(const ScalarConverter& other);
		// copy assignement constructor
		ScalarConverter &operator=(const ScalarConverter& other);
		// destructor
		~ScalarConverter();

		static float parseFloat(const std::string& str);
		static double parseDouble(const std::string& str);
		static int parseInt(const std::string& str);

		static bool	checkIfFloat(const std::string &input);
		static bool	checkIfDouble(const std::string &input);
		static bool	checkIfInt(const std::string &input);
		static void	printConversions(double val);

	public:
		static void	convert(const std::string& input);
};

#endif