/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:01:15 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/31 10:19:50 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) {
	(void)other;
};

Intern&	Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
};

Intern::~Intern() {};

AForm*	Intern::createPresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
};

AForm*	Intern::createRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
};

AForm*	Intern::createShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
};

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) {
		typedef AForm* (*FormCreator)(std::string const &);
		std::string nameList[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
		FormCreator functionList[] = {
			createPresidentialPardonForm,
			createRobotomyRequestForm,
			createShrubberyCreationForm
		};
		
		for (int i = 0; i < 3; i++){
			if (formName == nameList[i]){
				std::cout << "Intern creates " << formName << " form.\n";
				return functionList[i](target);
			}
		}
		std::cerr << RED << "Faulty form: " << formName << ". Not able to create that one!\n" << RESET;
		return NULL;	
	};