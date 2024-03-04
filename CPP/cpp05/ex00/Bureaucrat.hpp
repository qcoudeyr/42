/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:18:59 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/03/04 16:54:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;

public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade too low";
		}
	};
	Bureaucrat(const std::string& name, int grade);
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	friend ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat) {
		os << bureaucrat._name << ", bureaucrat grade " << bureaucrat._grade << ".";
			return os;
		}
};

#endif
