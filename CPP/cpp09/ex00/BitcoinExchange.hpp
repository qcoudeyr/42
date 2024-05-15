#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>


class BitcoinExchange
{

	public:
		BitcoinExchange(const std::string& filename);
		~BitcoinExchange();

		double		getExchangeRate(const std::string& date) const;
		bool		isValid(void);

	private:
		bool		valid;
		std::map<std::string,	double> exchangeRates;

};

#endif /* ************************************************* BITCOINEXCHANGE_H */
