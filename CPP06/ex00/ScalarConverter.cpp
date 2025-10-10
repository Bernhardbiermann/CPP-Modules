/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:06:16 by bbierman          #+#    #+#             */
/*   Updated: 2025/09/11 17:00:09 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
};

ScalarConverter::~ScalarConverter() {};

bool	ScalarConverter::checkIfDouble(const std::string &input)
{
	if (input.empty())
		return false;
	std::string core = input;
	bool hasDot = false;
	bool hasDigit = false;
	bool hasE = false;
	bool hasEPre = false;
	size_t i = 0;
	if (core[i] == '-' || core[i] == '+')
		i++;
	for (; i < core.length(); i++){
		if (!std::isdigit(core[i])){
			if (core[i] == '.' && !hasDot){
				hasDot = true;
				hasDigit = false;
				continue;
			}
			if (core[i] == 'e' && !hasE){
				hasE = true;
				hasDigit =false;
				continue;
			}
			if ((core[i] == '+' && !hasEPre) || (core[i] == '+' && !hasEPre)){
				hasEPre = true;
				hasDigit =false;
				continue;
			}
			return false;
		}
		hasDigit = true;
	}
	return hasDigit;
};

bool	ScalarConverter::checkIfFloat(const std::string &input)
{
	if (input.empty() || input[input.length() - 1] != 'f')
		return false;
	std::string core = input.substr(0, input.length() - 1);
	if (!checkIfDouble(core))
		return false;
	else
		return true;
};

bool	ScalarConverter::checkIfInt(const std::string &input)
{
	if (input.empty())
		return false;
	size_t i = 0;
	int prefix = 1;
	long nbr = 0;
	if (input[i] == '-' || input[i] == '+'){
		if (input[i] == '-')
			prefix = -1;
		i++;
	}
	for (; i < input.length(); i++){
		if (!std::isdigit(input[i]))
			return false;
		nbr = nbr * 10 + (input[i] - '0');
	}
	nbr *= prefix;
	return true;
};

void	ScalarConverter::printConversions(double val) {
	// char
	if (val > 127 || val < 0)
		std::cout << RED "char" RESET ": Impossible\n";
	else if (std::isprint(static_cast<char>(val)))
		std::cout << GREEN "char" RESET ": \'" + std::string(1, static_cast<char>(val)) + "\'\n";
	else
		std::cout << RED "char" RESET ": Non displayable" << "\n";
	// int
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout << RED "int" RESET << ": Impossible\n";
	else
		std::cout << GREEN "int" RESET << ": " << static_cast<int>(val) << "\n";
	// float
	if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
		std::cout << BLUE "float" RESET << ": Infinity\n";
	else
		std::cout << GREEN "float" RESET << ": " << static_cast<float>(val) << "f\n";
	// double
	std::cout << GREEN "double" RESET << ": " << static_cast<double>(val) << "\n";
};

void	ScalarConverter::convert(const std::string& input){
	std::cout << std::fixed << std::setprecision(1);
	if (input == "nan" || input == "nanf"){
		std::cout
		<< RED "char" RESET << ": impossible\n"
		<< RED "int" RESET << ": impossible\n"
		<< GREEN "float" RESET << ": nanf\n"
		<< GREEN "double" RESET << ": nan\n";
		return;
	}
	if (input == "+inff" || input == "inff" ||input == "+inf" || input == "inf"){
		std::cout
		<< RED "char" RESET << ": impossible\n"
		<< RED "int" RESET << ": impossible\n"
		<< GREEN "float" RESET << ": inff\n"
		<< GREEN "double" RESET << ": inf\n";
		return;
	}
	if (input == "-inff" || input == "-inf"){
		std::cout
		<< RED "char" RESET << ": impossible\n"
		<< RED "int" RESET << ": impossible\n"
		<< GREEN "float" RESET << ": -inff\n"
		<< GREEN "double" RESET << ": -inf\n";
		return;
	}
	if ((input.length() == 1) && !std::isdigit(input[0])){
		char c = input[0];
		if (std::isprint(c)){
			std::cout << GREEN "char" RESET << ": " << c << "\n"
			<< GREEN "int" RESET << ": " << static_cast<int>(c) << "\n"
			<< GREEN "float" RESET << ": " << static_cast<float>(c) << "f\n"
			<< GREEN "double" RESET << ": " << static_cast<double>(c) << "\n";
			return;
		}
		else {
			std::cout
			<< RED "char" RESET << ": Non displayable\n"
			<< GREEN "int" RESET << ": " << static_cast<int>(c) << "\n"
			<< GREEN "float" RESET << ": " << static_cast<float>(c) << "f\n"
			<< GREEN "double" RESET << ": " << static_cast<double>(c) << "\n";
			return;
		}
	}
	try{
		if (checkIfFloat(input)){
			std::string	core = input.substr(0, input.size() - 1); // Clean up the 'f' at the end
			double	val = std::strtod(core.c_str(), NULL);
			printConversions(val);
			return;
		}
		else if (checkIfDouble(input) || checkIfInt(input)){
			double	val = std::strtod(input.c_str(), NULL);
			printConversions(val);
			return;
		}
		else {
			std::cerr << RED "Input couldn't be parsed as char/int/float/double." << RESET << "\n";
		}
	} catch (std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << "\n" RESET;
	}
};