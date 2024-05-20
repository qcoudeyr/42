/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:52:50 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/20 10:14:37 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " input_file.txt" << std::endl;
		return 1;
	}

	BitcoinExchange bitcoin("data.csv");
	if (bitcoin.isValid() == false) {
		return 1;
	}

	std::ifstream inputfile(argv[1]);
	if (!inputfile) {
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputfile, line)) {
		std::istringstream iss(line);
		std::string date;
		double value;
		char delimiter;
		if (iss >> date >> delimiter >> value && delimiter == '|' && value >= 0 && value <= 1000) {
			double exchangeRate = bitcoin.getExchangeRate(date);
			if (exchangeRate != 0.0) {
				std::cout << date << " => " << value << " = ";
				std::cout << std::fixed << std::setprecision(2) << (value * exchangeRate) << std::endl;
			} else {
				std::cerr << "Error: no exchange rate found for date " << date << std::endl;
			}
		} else if (value < 0){
			std::cerr << "Error: not a positive number. => " << line << std::endl;
		} else if (value > 1000){
			std::cerr << "Error: number too large. => " << line << std::endl;
		} else if (line.find("date | value")) {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}

	return 0;
}
