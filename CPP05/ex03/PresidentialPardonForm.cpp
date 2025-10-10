/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:26:34 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 12:23:02 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm",25, 5), _target("Unnamed") {};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) 
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
	_target = other._target;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

std::string	PresidentialPardonForm::getTarget() const {
	return _target;
};

void	PresidentialPardonForm::executeAction(const Bureaucrat& executer) {

	if (this->checkGradeToExecute(executer)){
	std::cout 
	<< PURPLE 
	<< "Dear, beloved "
	<< ITALIC
	<< getTarget()
	<< RESET
	<< PURPLE
	<< ", you have been pardoned by Zaphod Beeblebrox."
	<< std::endl;
	}
};