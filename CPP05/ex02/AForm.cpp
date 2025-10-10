/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:55:16 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 17:19:46 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : 
	_name("Unknown"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(150) {};

AForm::AForm(const std::string newName,
		const int gradeToSign,
		const int gradeToExecute) :
	_name(newName),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
		if ((_gradeToSign < 1) || (_gradeToExecute < 1))
			throw GradeTooHighException();
		if ((_gradeToSign > 150) || (_gradeToExecute > 150))
			throw GradeTooLowException();
};

AForm::AForm(const AForm& other) : 
	_name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute){};

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
};

AForm::~AForm() {};

std::string		AForm::getName() const {
	return _name;
};

bool	AForm::isSigned() const {
	return _signed;
};

int		AForm::getGradeToSign() const {
	return _gradeToSign;
};

int		AForm::getGradeToExecute() const {
	return _gradeToExecute;
};

void	AForm::beSigned(const Bureaucrat& b) {
	if (_signed)
		throw FormIsSignedException();
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else {
		throw GradeTooLowException();
	}
};

bool	AForm::checkGradeToExecute(const Bureaucrat& b) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (!(b.getGrade() <= _gradeToExecute))
		throw GradeTooLowException();
	return true;
};

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName()
	<< ", signed: " 
	<< std::boolalpha 
	<< f.isSigned()
	<< ", grade to sign: "
	<< f.getGradeToSign()
	<< ", grade to execute: "
	<< f.getGradeToExecute();
	return os;
};

