#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	std::ifstream infile(filename.c_str());
	if (!infile) {
		valid = false;
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::string dateStr;
		double rate;
		char delimiter;

		if (iss >> dateStr >> delimiter >> rate && delimiter == '|' && rate >= 0 && rate <= 1000) {
			exchangeRates[dateStr] = rate;
		}
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/


double BitcoinExchange::getExchangeRate(const std::string& date) const {
	// Find the closest date in the database
	std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
	if (it != exchangeRates.begin()) {
		--it; // Get the lower date
	}
	return (it != exchangeRates.end()) ? it->second : 0.0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool BitcoinExchange::isValid(void){
	return valid;
}

/* ************************************************************************** */
