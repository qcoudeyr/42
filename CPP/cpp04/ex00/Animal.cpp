/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:41:17 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 12:52:06 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default Animal")
{
	std::cout<<"Animal constructor called !"<<std::endl;
}
Animal::~Animal()
{
	std::cout<<"Animal destructor called !"<<std::endl;
}
