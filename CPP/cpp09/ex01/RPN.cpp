/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:27:27 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/24 15:29:49 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <string>
#include <stack>
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	(void) src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void) rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	(void) i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Invalid expression");
			}
			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();
			int result = performOperation(token[0], operand1, operand2);
			stack.push(result);
		} else if (token.length() == 1 && isdigit(token[0])) {
			stack.push(token[0] - '0');
		} else {
			throw std::runtime_error("Invalid token");
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Invalid expression");
	}

	return stack.top();
}

bool RPN::isOperator(char token) const {
	return token == '+' || token == '-' || token == '*' || token == '/';
}

int RPN::performOperation(char operation, int operand1, int operand2) const {
	switch (operation) {
		case '+': return operand1 + operand2;
		case '-': return operand1 - operand2;
		case '*': return operand1 * operand2;
		case '/': return operand1 / operand2;
		default: throw std::runtime_error("Unknown operator");
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
