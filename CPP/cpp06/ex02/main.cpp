/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:18:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/16 09:30:45 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

void	identify(Base* p)
{
	std::cout << "Identify the class with mPointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;

}

void	identify(Base &p)
{
	try
	{
		A	&derivA = dynamic_cast<A &>(p);
		(void)derivA;
		std::cout << "reference identifier: this is a type A" << std::endl;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		B    &derivB = dynamic_cast<B &>(p);
		(void)derivB;
		std::cout << "reference identifier: this is a type B" << std::endl;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		C    &derivC = dynamic_cast<C &>(p);
		(void)derivC;
		std::cout << "reference identifier: this is a type C" << std::endl;
	}
	catch(std::exception &e)
	{
	}
}

int main() {
	Base *base = new Base();
	identify(base->generate());
	identify(*base->generate());
	delete base;
	return 0;
}
