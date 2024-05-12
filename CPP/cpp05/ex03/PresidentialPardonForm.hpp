/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:35:41 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 18:01:37 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Aform.hpp"

class PresidentialPardonForm : public Aform
{
private:
	std::string _target;

	PresidentialPardonForm();

public:
	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( const PresidentialPardonForm& src );
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

	void execute( const Bureaucrat& executor ) const;
};

#endif
