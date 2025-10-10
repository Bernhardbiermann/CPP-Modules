/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:41:45 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/23 15:34:27 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;

	public:
		// constructor
		RobotomyRequestForm();
		// target constructor 
		RobotomyRequestForm(const std::string target);
		// copy constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);
		// copy assignment constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		// destructor
		~RobotomyRequestForm();

		std::string	getTarget() const;

		void	executeAction(const Bureaucrat& executer);
};

#endif