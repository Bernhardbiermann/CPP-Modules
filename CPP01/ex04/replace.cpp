/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbierman <bbierman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:24:06 by bbierman          #+#    #+#             */
/*   Updated: 2025/07/09 12:58:16 by bbierman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout std::cin, std::cerr
#include <fstream> //std::ifstream std::ofstream
#include <string> // std::string
#include <sstream> // std::stringstream

std::string customReplace(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t pos = 0;
	size_t found;

	// Falls found s1 nicht findet, wird der Wert npos (no position - keine gueltige Position) zurueckgegben
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos);
	return result;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "The input should look like: " << argv[0] 
			<< " <filename> <search_string> <replace_string>"
			<< std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if ( filename.empty() || s1.empty())
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Can't open input file." << std::endl;
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Can't create output file." << std::endl;
		return 1;
	}
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	outfile << customReplace(content, s1, s2) << std::endl;
	infile.close();
	outfile.close();
	return 0;
}