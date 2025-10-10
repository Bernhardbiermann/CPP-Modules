/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:38:34 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/23 15:34:22 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		// constructor
		ShrubberyCreationForm();
		// target constructor 
		ShrubberyCreationForm(const std::string target);
		// copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		// copy assignment constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		// destructor
		~ShrubberyCreationForm();

		std::string	getTarget() const;

		void	executeAction(const Bureaucrat& executer);
};

#endif
