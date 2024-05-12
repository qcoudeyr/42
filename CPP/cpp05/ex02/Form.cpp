/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:55 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:31:01 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string& name, int gradeToSign ) : _Name( name ), _RequiredGradeToSign( gradeToSign ), _RequiredGradeToExecute( 0 ) {
	if ( gradeToSign < 1 )
		throw Form::GradeTooHighException();
	if ( gradeToSign > 150 )
		throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : _Name( src.getName() ), _RequiredGradeToSign( src.getGradeToSign() ), _RequiredGradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

Form&	Form::operator=( const Form& rhs ) {
	if ( this != &rhs )
		_Signed = rhs.getSigned();
	return *this;
}

std::string Form::getName() const {
	return _Name;
}

bool	Form::getSigned() const {
	return _Signed;
}

int	Form::getGradeToSign() const {
	return _RequiredGradeToSign;
}

int	Form::getGradeToExecute() const {
	return _RequiredGradeToExecute;
}

void	 Form::beSigned(const Bureaucrat& bureaucrat) {
	if ( bureaucrat.getGrade() > _RequiredGradeToSign )
		throw Form::GradeTooLowException();
	_Signed = true;
}

std::ostream&	operator<<( std::ostream& o, const Form& rhs ) {
	o << "Form name: " << rhs.getName() << std::endl
	  << "Is Signed : " << (rhs.getSigned() ? "Yes" : "No")  << std::endl
	  << "Grade to sign: " << rhs.getGradeToSign() << std::endl
	  << "Grade to execute: " << rhs.getGradeToExecute();
	return o;
}
