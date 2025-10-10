/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:20:39 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/21 14:50:09 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// constructor
		Form();
		// parametric constructor
		Form(const std::string newName, const int gradeToSign, const int gradeToExecute);
		// copy constructor
		Form(const Form& other);
		// copy assignment constructor
		Form& operator=(const Form& other);
		// destructor
		~Form();
		
		std::string		getName() const;
		bool			isSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(const Bureaucrat& b);
		
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
};

std::ostream &operator<<(std::ostream& lhs, const Form& rhs);

#endif
