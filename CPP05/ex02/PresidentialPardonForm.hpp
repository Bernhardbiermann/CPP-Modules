/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:26:37 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/23 15:52:50 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PURPLE	"\033[35m"
#define CYAN	"\033[36m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
		// constructor
		PresidentialPardonForm();
		// target constructor 
		PresidentialPardonForm(const std::string target);
		// copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);
		// copy assignment constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		// destructor
		~PresidentialPardonForm();

		std::string	getTarget() const;

		void	executeAction(const Bureaucrat& executer);
};

#endif