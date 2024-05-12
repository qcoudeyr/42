/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:35:43 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 18:02:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Aform.hpp"

class RobotomyRequestForm : public Aform
{
private:
	const std::string	_target;

	RobotomyRequestForm();

public:
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm& src );
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=( RobotomyRequestForm& rhs );

	void	execute( const Bureaucrat& executor ) const;
};

#endif
