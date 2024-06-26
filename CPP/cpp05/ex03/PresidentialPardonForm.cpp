/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:35:39 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 18:03:35 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Aform( "PresidentialPardonForm", 25, 5 ), _target( target ) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Aform( src ), _target( src._target ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw Aform::GradeTooLowException();
	else {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
