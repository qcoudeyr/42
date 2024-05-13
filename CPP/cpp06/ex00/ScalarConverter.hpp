/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:57 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 20:34:34 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <limits>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

class ScalarConverter
{

	public:
	static void		convert(const std::string input);

	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();
		ScalarConverter &		operator=( ScalarConverter const & rhs );

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */
