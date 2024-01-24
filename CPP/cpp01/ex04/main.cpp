/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/24 14:21:29 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceWord(const std::string &original, const std::string &target, const std::string &replacement) {
	std::string result = original;
	size_t startPos = result.find(target);

	while (startPos != std::string::npos) {
		result = result.substr(0, startPos) + replacement + result.substr(startPos + target.length());

		startPos = result.find(target, startPos + replacement.length());
	}

	return result;
}

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
			for (int i = 0; s1[i]; i++)
			{
				while (line[found] == s1[i])

			}
		}
		else
			outputFile << line;
	}

	inputFile.close();
	outputFile.close();
	return (0);
}
