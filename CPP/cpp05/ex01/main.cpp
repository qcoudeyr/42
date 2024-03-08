/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:24:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/03/08 16:23:37 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("high", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat lowcrat("low", 150);
		std::cout << lowcrat << std::endl;
		lowcrat.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat normalcrat("Normal down", 75);
		std::cout << normalcrat << std::endl;
		normalcrat.decrementGrade();
		std::cout << normalcrat << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat normalupcrat("normal up", 20);
		std::cout << normalupcrat << std::endl;
		normalupcrat.incrementGrade();
		std::cout << normalupcrat << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
