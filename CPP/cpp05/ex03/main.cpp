/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:24:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 19:08:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	Bureaucrat bureaucrat("Sophie", 2);

	{
		Intern	someRandomIntern;
		Aform*	rrf;

		rrf = someRandomIntern.makeForm("\'robotomy\'", "Wrong Form");
		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}

	return EXIT_SUCCESS;
}
