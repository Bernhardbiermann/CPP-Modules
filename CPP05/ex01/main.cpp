/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:31:24 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/21 15:08:07 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat Wolfgang("Wolfgang", 150);
	Form holyForm("HolyForm", 25, 50);

	std::cout<< GREEN
		<< "The holy form has been created by the godfather of bureaucrats, the mysterious Olaf.\n"
		<< RESET
		<< BLUE
		<< holyForm << '\n'
		<< GREEN
		<< "The resurrection of Wolfgang happened.\n"
			"Once he starts again, his grade has been set to 150.\n"
		<< RESET
		<< BLUE
		<< "Let's look at Wolfgang's grade: "
		<< Wolfgang.getGrade()
		<< '\n'
		<< RESET << std::endl;

	std::cout
		<< ITALIC
		<< "Someone says: \"Wolfgang, good to have you back! Can you please sign this form?\"\n"
		<< RESET
		<< YELLOW
		<< "As a true bureaucrat he jumps into action and tries to sign the form...\n\n"
		<< RESET;
	
	try{
		Wolfgang.signForm(holyForm);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}
	
	std::cout
		<< ITALIC
		<< "\nSomeone says: \"Oh no! We need to call the chief inspector immediately!\"\n"
		<< RESET
		<< ITALIC
		<< "The chief inspector arrives, beaming with joy, and shouts:\n"
			"\"FINALLY HE'S BACK! WE'RE SETTING YOUR GRADE TO 1!\"\n"
			"He steps forward to adjust Wolfgang's grade...\n"
		<< RESET
		<< std::endl;

	try {
		Wolfgang.setGrade(1);
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	std::cout
		<< BLUE
		<< "Wolfgang's new grade is: " << Wolfgang.getGrade() << '\n'
		<< RESET
		<< YELLOW
		<< "\nWolfgang is in a rush now.\n"
			"Without hesitation, he signs the holy form.\n"
		<< RESET
		<< std::endl;

	try {
		Wolfgang.signForm(holyForm);
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	std::cout
		<< YELLOW
		<< "\nWolfgang strikes again!\n"
			"Thank you, Wolfgang.\n"
		<< RESET
		<< std::endl;

return 0;
};