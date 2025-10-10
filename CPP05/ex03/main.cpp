/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:31:24 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/31 10:27:00 by bbierman         ###   ########.fr       */
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

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << BLUE << "=== Starting Intern Office Simulation ===\n" << RESET;

	Intern intern;
	Bureaucrat wolfgang("Wolfgang", 1);

	std::string targets[] = { 
		"TreeWorld", 
		"Bender", 
		"Olaf" 
	};
	std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i) {
		std::cout << YELLOW << "\n[TASK] Requesting form: " << forms[i]
		          << " for target: " << targets[i] << RESET << std::endl;

		AForm* form = intern.makeForm(forms[i], targets[i]);
		if (form) {
			try {
				wolfgang.signForm(*form);
				wolfgang.executeForm(*form);
			} catch (std::exception& e) {
				std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
			}
			delete form;
		}
	}

	std::cout << YELLOW << "\n[TASK] Requesting unknown form: coffee request\n" << RESET;
	AForm* failForm = intern.makeForm("coffee request", "MachineRoom");
	if (failForm)
		delete failForm;

	std::cout << BLUE << "\n=== Intern Office Simulation complete ===\n" << RESET;
	return 0;
}