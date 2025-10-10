/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:44:18 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 12:56:55 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("Unnamed") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
};

std::string	ShrubberyCreationForm::getTarget() const {
	return _target;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void	ShrubberyCreationForm::executeAction(const Bureaucrat& executer) {
	
	if (this->checkGradeToExecute(executer)){
		std::string filename = "ShrubberySource.txt";
		
		std::ifstream infile(filename.c_str());
		if (!infile)
			throw std::runtime_error("Opening infile failed!");
		std::ofstream	outfile((getTarget() + "_shrubbery").c_str());
		if (!outfile)
			throw std::runtime_error("Can't create outfile!");
		outfile << infile.rdbuf();
	}
};