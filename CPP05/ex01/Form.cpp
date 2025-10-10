/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:55:16 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/21 17:26:40 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
	_name("Unknown"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(150) {};

Form::Form(const std::string newName, const int gradeToSign, const int gradeToExecute):
	_name(newName),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
		if ((_gradeToSign < 1) || (_gradeToExecute < 1))
			throw GradeTooHighException();
		if ((_gradeToSign > 150) || (_gradeToExecute > 150))
			throw GradeTooLowException();
};

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
};

Form::~Form() {};

std::string		Form::getName() const {
	return _name;
};

bool	Form::isSigned() const {
	return _signed;
};

int		Form::getGradeToSign() const {
	return _gradeToSign;
};

int		Form::getGradeToExecute() const {
	return _gradeToExecute;
};

void	Form::beSigned(const Bureaucrat& b) {
	int	bGrade = b.getGrade();
	if (bGrade <= _gradeToSign)
		_signed = true;
	else {
		throw GradeTooLowException();
	}
};

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName()
	<< ", signed: " 
	<< std::boolalpha 
	<< f.isSigned()
	<< ", grade to sign: "
	<< f.getGradeToSign()
	<< ", grade to execute: "
	<< f.getGradeToExecute();
	return os;
}


