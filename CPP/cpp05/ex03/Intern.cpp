/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:32:41 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 19:08:02 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Aform*	Intern::makeForm( std::string name, std::string target )
{
	std::string formNames[] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon",
	};

	Aform*	forms[] = {
		new ShrubberyCreationForm( target ),
		new RobotomyRequestForm( target ),
		new PresidentialPardonForm( target )
	};

	Aform* validForm = NULL;

	for ( int i(0); i < 3; i++ ) {
		if ( name == formNames[i] ) {
			validForm = forms[i];
		} else {
			delete forms[i];
		}
	}

	validForm == NULL ? std::cout << "Intern can't create " << name << " form !" << std::endl : std::cout << "Intern creates " << name << std::endl;

	return validForm;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
