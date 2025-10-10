/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:55:27 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/04 10:22:59 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

struct PhoneBook {
	private:
		Contact	contacts[8];
		int		i;
		int		nbr_contacts;

		std::string	read_line(std::string prompt);
		std::string	get_nbr(std::string promtp);
		std::string truncate_string(std::string str);
	
	public:
		PhoneBook();

		void	add();
		void	fill();
		void	print_phonebook();
		void	print_contact();
		bool	empty();
};

#endif