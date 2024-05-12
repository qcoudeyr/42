/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:18:59 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:27:03 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdlib>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

	Bureaucrat();

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat& operator=( const Bureaucrat& rhs );

	std::string getName() const;
	int		getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade too high !";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade too low !";
			}
	};

	void	signForm( Form& form );

};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );
#endif
