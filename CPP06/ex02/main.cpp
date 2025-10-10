/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:47:39 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/28 19:28:19 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main() {
	std::srand(std::time(NULL)); 
	for (int i = 0; i < 5; i++){
		Base* obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
	}
}