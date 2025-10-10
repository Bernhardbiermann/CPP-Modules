/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:31:24 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 15:01:56 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define BLUE   "\033[34m"
#define YELLOW "\033[33m"
#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define RESET  "\033[0m"
#define ITALIC "\033[3m"

int main() {
//	srand(time(NULL));
	Bureaucrat Wolfgang("Wolfgang", 150);
	std::cout
		<< GREEN
		<< "Welcome: The mysterious Olaf conjures up three mighty forms...\n"
		<< RESET;

	// ShrubberyCreationForm
	{
		std::cout
			<< BLUE
			<< "\n=== ShrubberyCreationForm (sign:145, exec:137) ===\n"
			<< RESET;
		ShrubberyCreationForm shrubForm("Garden");

		std::cout
			<< ITALIC
			<< "Wolfgang tries to sign the shrubbery form...\n"
			<< RESET;
		try {
			Wolfgang.signForm(shrubForm);
		} catch (std::exception &e) {
			std::cerr << RED
						<< "Exception error: " << e.what() << '\n'
						<< RESET;
		}

		std::cout
			<< YELLOW
			<< "\nOlaf upgrades Wolfgang's rank to 145!\n"
			<< RESET;
		try {
			Wolfgang.setGrade(145);
		} catch (std::exception &e) {
			std::cerr << RED << "Exception: " << e.what() << '\n' << RESET;
		}

		std::cout
			<< ITALIC
			<< "Now Wolfgang tries to sign ...\n"
			<< RESET;
		Wolfgang.signForm(shrubForm);

		std::cout
			<< ITALIC
			<< "Now Wolfgang tries to execute...\n"
			<< RESET;
		Wolfgang.executeForm(shrubForm);
		
		std::cout
			<< YELLOW
			<< "\nOlaf upgrades Wolfgang's rank to 137!\n"
			<< RESET;
		try {
			Wolfgang.setGrade(137);
		} catch (std::exception &e) {
			std::cerr << RED << "Exception: " << e.what() << '\n' << RESET;
		}

		std::cout
			<< ITALIC
			<< "Now Wolfgang signs successfully...\n"
			<< RESET;
		Wolfgang.signForm(shrubForm);

		std::cout
			<< ITALIC
			<< "Now Wolfgang executes the shrubbery form...\n"
			<< RESET;
		Wolfgang.executeForm(shrubForm);
	}

	// RobotomyRequestForm
	{
		std::cout
			<< BLUE
			<< "\n=== RobotomyRequestForm (sign:72, exec:45) ===\n"
			<< RESET;
		RobotomyRequestForm roboForm("Marvin");

		std::cout
			<< ITALIC
			<< "Wolfgang attempts to sign the robotomy form...\n"
			<< RESET;
		try {
			Wolfgang.signForm(roboForm);
		} catch (std::exception &e) {
			std::cerr << RED
						<< e.what() << '\n'
						<< RESET;
		}

		std::cout
			<< YELLOW
			<< "Olaf boosts Wolfgang's rank to 45!\n"
			<< RESET;
		try {
			Wolfgang.setGrade(45);
		} catch (std::exception &e) {
			std::cerr << RED  << e.what() << '\n' << RESET;
		}

		std::cout
			<< GREEN
			<< "Wolfgang signs the robotomy form...\n"
			<< RESET;
		Wolfgang.signForm(roboForm);

		std::cout
			<< ITALIC
			<< "Bzzz... Bzzz... Wolfgang performs the robotomy three times:\n"
			<< RESET;
		Wolfgang.executeForm(roboForm);
		Wolfgang.executeForm(roboForm);
		Wolfgang.executeForm(roboForm);
	}

	// PresidentialPardonForm
	{
		std::cout
			<< BLUE
			<< "\n=== PresidentialPardonForm (sign:25, exec:5) ===\n"
			<< RESET;
		PresidentialPardonForm pardonForm("Arthur Dent");

		std::cout
			<< ITALIC
			<< "Wolfgang tries to execute without signing...\n"
			<< RESET;
		try {
			Wolfgang.executeForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << RED
						<< e.what() << '\n'
						<< RESET;
		}

		std::cout
			<< YELLOW
			<< "Olaf grants Wolfgang rank 5!\n"
			<< RESET;
		try {
			Wolfgang.setGrade(5);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		std::cout
			<< GREEN
			<< "Wolfgang signs the pardon form...\n"
			<< RESET;
		Wolfgang.signForm(pardonForm);

		std::cout
			<< ITALIC
			<< "And now the ceremonial moment:\n"
			<< RESET;
		Wolfgang.executeForm(pardonForm);
	}

	std::cout
		<< GREEN
		<< "\nAll forms have been tested. Wolfgang, you are our hero!\n"
		<< RESET;

	return 0;
};
