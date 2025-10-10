/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:36:22 by bbierman          #+#    #+#             */
/*   Updated: 2025/09/08 15:46:11 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		// constructor
		Bureaucrat();
		// name&grade constructor
		Bureaucrat(const std::string newName, const int newGrade);
		// copy constructor
		Bureaucrat(const Bureaucrat& other);
		// copy assignement constructor
		Bureaucrat &operator=(const Bureaucrat& other);
		// destructor
		~Bureaucrat();

		//getters
		const std::string	getName() const;
		int				getGrade() const;
		
		//grade functions
		void	setGrade(int const newGrade);
		void	increment();
		void	decrement();

		void	signForm(Form& f);

		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw()
				{
					return "Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw()
				{
					return "Grade too low!";
				}
		};
};

std::ostream &operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif