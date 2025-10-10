/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:39:25 by bbierman          #+#    #+#             */
/*   Updated: 2025/09/08 15:49:45 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {
	std::cout << GREEN << "Bureaucrat default constructor called" 
	<< RESET << std::endl;
};

Bureaucrat::Bureaucrat(const std::string newName, int newGrade) :
 _name(newName) {
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	_grade = newGrade;
	std::cout << GREEN << "Bureaucrat name&grade constructor called" 
	<< RESET << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
 _name(other._name), _grade(other._grade) {
	std::cout << GREEN << "Bureaucrat copy constructor called" 
	<< RESET << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->_grade = other._grade;
	}
	std::cout << GREEN << "Bureaucrat copy assignement constructor called" 
	<< RESET << std::endl;
	return *this;
};

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
};

const std::string	Bureaucrat::getName() const {
	return _name;
};

int	Bureaucrat::getGrade() const {
	return _grade;
};

void	Bureaucrat::setGrade(int const newGrade) {
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	_grade = newGrade;
};

void	Bureaucrat::increment(){
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
};

void	Bureaucrat::decrement() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm& f){
	try{
		f.beSigned(*this);
		std::cout
		<< GREEN 
		<< _name 
		<< " signed " 
		<< f.getName() 
		<< " successfully!\n"
		<< RESET;
	} catch (std::exception &e){
		std::cerr 
		<< "Couldn\'t sign " 
		<< f.getName() 
		<< ". " 
		<< e.what() 
		<< '\n';
	}
};

void	Bureaucrat::executeForm(AForm& f){
	if (_grade <= f.getGradeToExecute()){
		std::cout 
		<< GREEN
		<< getName()
		<< " executed "
		<< f.getName()
		<< std::endl;
		f.executeAction(*this);
	} else {
		std::cerr
		<< RED
		<< "I'm not allowed to do this!"
		<< RESET
		<< std::endl;
	}
};

std::ostream &operator<<(std::ostream& lhs, const Bureaucrat& rhs){
	lhs << BLUE 
	<< rhs.getName() 
	<< ", bureaucrat grade " 
	<< rhs.getGrade();
	return lhs;
};