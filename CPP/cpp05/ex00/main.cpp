/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:24:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/03/04 16:24:37 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("John Doe", 75);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << "After decrement: " << bureaucrat << std::endl;

		// Testing exception handling
		Bureaucrat highGradeBureaucrat("Jane Doe", 1);
		highGradeBureaucrat.incrementGrade();  // This should throw GradeTooHighException

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
