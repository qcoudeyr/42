/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:35:45 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 18:02:41 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Aform.hpp"
#include <fstream>

class ShrubberyCreationForm : public Aform {

private:
	const std::string	_target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( const ShrubberyCreationForm& src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm&  operator=( ShrubberyCreationForm& rhs );

	void	execute( const Bureaucrat& executor ) const;

};

#endif
