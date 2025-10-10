/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:43:07 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 15:14:38 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm",72, 45), _target("Unnamed") {};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other){
	_target = other._target;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
};

void	RobotomyRequestForm::executeAction(const Bureaucrat& executer) {
	
	if (this->checkGradeToExecute(executer)){
		std::cout 
		<< PURPLE 
		<< "Bip Bip .... zrrr zrrr zrrr..."
		<< ITALIC
		<< "drilling noise"
		<< RESET
		<< PURPLE
		<< "Bip Bip .... zrrr zrrr zrrr..."
		<< std::endl;
		
		if (std::rand() % 2){
			std::cout 
			<< GREEN 
			<< getTarget() 
			<< " has been robotomized successfully!" 
			<< std::endl;
		} else {
			std::cout 
			<< RED 
			<< "Robotomy failed on " 
			<< getTarget()
			<< "!"
			<< std::endl;
		}
	}
};