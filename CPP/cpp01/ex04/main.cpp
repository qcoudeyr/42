/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 11:42:20 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	const char		*filePath = "origin.file";
	std::string		s1 = "ipsum";
	std::string		s2 = "TEST";
	std::string		line;

	std::ifstream inputFile(filePath);
	if (!inputFile.is_open())
		return (std::cerr << "Error opening the file: " << filePath << std::endl, 1);

	std::string outputPath = (std::string)filePath + ".replace";
	std::ofstream outputFile(outputPath.c_str());
	if (!outputFile.is_open())
		return (std::cerr << "Error creating the file: " << filePath << std::endl, 1);
	while (std::getline(inputFile, line))
	{
		size_t found = line.find(s1);
		if (found != std::string::npos)
		{
			std::cout << "Substring found at position " << found << std::endl;
		}
		else
			outputFile << line;
	}

	inputFile.close();
	outputFile.close();
	return (0);
}
