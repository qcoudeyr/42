/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:53 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/04/23 10:38:20 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
	private:

		const std::string _Name;
		bool _Signed;
		const int _RequiredGradeToSign;
		const int _RequiredGradeToExecute;

	public:
		Form();
		Form( Form const & src );
		~Form();

		Form &		operator<<( Form const & rhs );
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
