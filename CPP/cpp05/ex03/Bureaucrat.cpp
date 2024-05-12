/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:19:01 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:58:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( const std::string& name, int grade ) : name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : name(src.name), grade(src.grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if ( this != &rhs )
		grade = rhs.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void    Bureaucrat::incrementGrade() {
	if ( grade - 1 < 1 )
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void    Bureaucrat::decrementGrade() {
	if ( grade + 1 > 150 )
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::signForm( Aform& Aform ) {
	try {
		Aform.beSigned( *this );
		std::cout << *this << " signed " << Aform.getName() << std::endl;
	} catch (Aform::GradeTooLowException &e) {
		std::cout << name << " coulnd't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void    Bureaucrat::executeForm( const Aform& Aform ) const {
	try {
		Aform.execute( *this );
	} catch ( std::exception& e ) {
		std::cout << name << " can't execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

