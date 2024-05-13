/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:23:04 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 21:31:16 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base() {}
	Base * generate(void);
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};


#endif

