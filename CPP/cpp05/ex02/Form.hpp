/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:28:26 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string _Name;
		bool _Signed;
		const int _RequiredGradeToSign;
		const int _RequiredGradeToExecute;

	public:
		Form( const std::string& name, int gradeToSign );
		Form( const std::string& name, int gradeToSign, int gradeToExecute );
		Form( const Form& src );
		~Form();

		Form&	operator=( const Form& rhs );

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif // FORM_HPP
