/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:20:39 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/26 17:22:11 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// constructor
		AForm();
		// parametric constructor
		AForm(const std::string newName, const int gradeToSign, const int gradeToExecute);
		// copy constructor
		AForm(const AForm& other);
		// copy assignment constructor
		AForm& operator=(const AForm& other);
		// destructor
		virtual ~AForm();
		
		std::string		getName() const;
		bool			isSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(const Bureaucrat& b);

		virtual void	executeAction(const Bureaucrat& executer) = 0;
		bool		checkGradeToExecute(const Bureaucrat& b) const; 
		
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw()
				{
					return "Grade too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(){
					return "Grade too low!";
				}
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw(){
					return "Form not signed!";
				}
		};

		class FormIsSignedException : public std::exception {
			public:
				const char* what() const throw(){
					return "Form is already signed!";
				}
		};
};

std::ostream &operator<<(std::ostream& lhs, const AForm& rhs);

#endif
