/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:31:24 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:07 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){
	
	Bureaucrat Wolfgang;

	std::cout 
	<< GREEN 
	<< "\nHere comes Wolfgang a freshly born bureaucrat\n" << RESET
	<< ITALIC 
	<< "Someone says: \"Stamp this stack of files Wolfgang\".\n" << RESET
	<< YELLOW 
	<< "Wolfgang stamps without the inkpad.\n" << RESET
	<< ITALIC 
	<< "Someone says: \"Poor Wolfgang now I have to lower your grade!\".\n" << RESET
	<< BLUE 
	<< "Let's look at Wolfgang\'s grade. His current grade is: " << Wolfgang.getGrade() << '\n' << RESET
	<< ITALIC 
	<< "Someone is trying to decrement Wolfgangs grade...\n" << RESET 
	<<std::endl;
	
	try{
		Wolfgang.decrement();
	} catch (std::exception& e) {
		std::cerr << "Caught exception: "<< e.what() << '\n';
	}
	
	std::cout 
	<< YELLOW 
	<< "\nWolfgang is in a rush now."
	<< "\nWithout hesitation he gets the inkpad and stamps all the files like a fury.\n" << RESET
	<< ITALIC 
	<< "Someone says: \"Well done Wolle! Here is your treat!\"."
	<< "\nSomeone is trying to increment Wolfgangs grade...\n" << RESET 
	<< std::endl;
	
	try{
		Wolfgang.increment();
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	
	std::cout 
	<< BLUE 
	<< "Wolfgangs current grade is: " << Wolfgang.getGrade() << '\n' << RESET
	<< YELLOW 
	<< "\nWolfgang is proud of his work.\n" << RESET
	<< ITALIC 
	<< "The chief inspector steps by. He is full of joy and shouts out loud:\n"
	<< "\"UNBELIEVABLE! THIS SHOULD HAVE BEEN THE WORK FOR YOUR WHOLE WEEK!"
	<< "WE NEED TO SET YOUR GRADE TO 0!\".\n"
	<< "The chief inspector is trying to set Wolfgangs grade to 0...\n" << RESET 
	<< std::endl;
	
	try{
		Wolfgang.setGrade(0);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	
	std::cout 
	<< ITALIC 
	<< "\n\"Ok..\" he says \"LET\'S TRY GRADE 1\"." << RESET 
	<< std::endl;
	
	try{
		Wolfgang.setGrade(1);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	
	std::cout 
	<< BLUE 
	<< "Let's look at Wolfgang\'s grade. His current grade is: " 
	<< Wolfgang.getGrade() << "\n\n" << RESET
	<< YELLOW 
	<< "Wolfgang doesn\'t feel well.\n" <<
	"He visits the doctor and without any cutbacks he enjoys his full lifelong pension till he dies one day.\n" << RESET
	<< std::endl;
	return (0);
}