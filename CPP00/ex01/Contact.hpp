/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:52:54 by bbierman          #+#    #+#             */
/*   Updated: 2025/06/04 10:09:42 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

struct	Contact{
	private:
		std::string	firstname;
		std::string	lastname;	
		std::string	nickname;
		std::string	phonenumber;
		std::string	secret;
	
	public:
		void	overwrite(std::string &first, std::string &last, \
			std::string &nick, std::string &phone, \
			std::string &sec)
			{
				firstname = first;
				lastname = last;
				nickname = nick;
				phonenumber = phone;
				secret = sec;
			}
		std::string get_first() const { return firstname; }
		std::string get_last() const { return lastname; }
		std::string get_nick() const { return nickname; }
		std::string get_phone() const { return phonenumber; }
		std::string get_secret() const { return secret; }
};

#endif
