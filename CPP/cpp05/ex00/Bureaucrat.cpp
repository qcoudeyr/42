/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:19:01 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/03/04 16:30:05 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string& getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade > 1) {
		grade--;
	} else {
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	if (grade < 150) {
		grade++;
	} else {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	} else {
		this->grade = grade;
	}
}

friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
