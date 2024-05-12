/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:35:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 18:02:23 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : Aform("Robotomy Request Aform", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : Aform(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm& rhs ) {
	( void )rhs;
	return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw Aform::GradeTooLowException();
	else {
		static int  i;
		if ( i % 2 == 0 )
			std::cout << "*VTTT* *VT* *VTTTTTTT*! " << _target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed on " << _target << " !"<< std::endl;
		i++;
	}
}
