/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:56:46 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 17:17:57 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Intern {
	private:
		static AForm*	createShrubberyCreationForm(std::string const & target);
		static AForm*	createRobotomyRequestForm(std::string const & target);
		static AForm*	createPresidentialPardonForm(std::string const & target);
	
	public:
		// constructor
		Intern();
		// copy constructor
		Intern(const Intern& other);
		// copy assignement constructor
		Intern &operator=(const Intern& other);
		// destructor
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target);
};

#endif