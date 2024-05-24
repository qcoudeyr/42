/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:27:25 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/24 15:28:18 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>


class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );
		int evaluate(const std::string& expression);

	private:
		bool isOperator(char token) const;
		int performOperation(char operation, int operand1, int operand2) const;
};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */
