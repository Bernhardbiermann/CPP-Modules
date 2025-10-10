/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:24:55 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/07 11:55:05 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //std::cout, std::cerr
//#include <string>
#include <cctype> // std::toupper
//using namespace std;

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc == 1){
		std::cout << ITALIC << "* LOUD AND UNBEAREBLE FEEDBACK NOISE *";
		return 0;
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (unsigned char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}