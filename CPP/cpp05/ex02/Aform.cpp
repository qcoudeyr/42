/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:55 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:58:09 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"

Aform::Aform( const std::string& name, int gradeToSign, int gradeToExecute) : _Name( name ), _RequiredGradeToSign( gradeToSign ), _RequiredGradeToExecute( gradeToExecute ) {
	if ( gradeToSign < 1 )
		throw Aform::GradeTooHighException();
	if ( gradeToSign > 150 )
		throw Aform::GradeTooLowException();
}

Aform::Aform( const Aform& src ) : _Name( src.getName() ), _RequiredGradeToSign( src.getGradeToSign() ), _RequiredGradeToExecute( src.getGradeToExecute() ) {}

Aform::~Aform() {}

Aform&	Aform::operator=( const Aform& rhs ) {
	if ( this != &rhs )
		_Signed = rhs.getSigned();
	return *this;
}

std::string Aform::getName() const {
	return _Name;
}

bool	Aform::getSigned() const {
	return _Signed;
}

int	Aform::getGradeToSign() const {
	return _RequiredGradeToSign;
}

int	Aform::getGradeToExecute() const {
	return _RequiredGradeToExecute;
}

void	 Aform::beSigned(const Bureaucrat& bureaucrat) {
	if ( bureaucrat.getGrade() > _RequiredGradeToSign )
		throw Aform::GradeTooLowException();
	_Signed = true;
}

std::ostream&	operator<<( std::ostream& o, const Aform& rhs ) {
	o << "Aform name: " << rhs.getName() << std::endl
	  << "Is Signed : " << (rhs.getSigned() ? "Yes" : "No")  << std::endl
	  << "Grade to sign: " << rhs.getGradeToSign() << std::endl
	  << "Grade to execute: " << rhs.getGradeToExecute();
	return o;
}

