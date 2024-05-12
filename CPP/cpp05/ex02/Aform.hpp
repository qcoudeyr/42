/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:43:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Aform
{
	private:

		const std::string _Name;
		bool _Signed;
		const int _RequiredGradeToSign;
		const int _RequiredGradeToExecute;

		Aform();

	public:
		Aform( const std::string& name, int gradeToSign, int gradeToExecute );
		Aform( const Aform& src );
		virtual    ~Aform();

		Aform&	operator=( const Aform& rhs );

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute( const Bureaucrat& executor ) const = 0;

	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Aform not signed"; }
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};
};

std::ostream&   operator<<( std::ostream& o, const Aform& rhs );

#endif
