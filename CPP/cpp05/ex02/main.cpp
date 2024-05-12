/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:24:26 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 17:29:22 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

	try {
		Bureaucrat bureaucrat("Sophie",11);
		Form form("Formulaire", 10);

		bureaucrat.signForm(form);

		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
