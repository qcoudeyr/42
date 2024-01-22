/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 14:00:13 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

void MenuHeader(std::string str)
{
	std::cout << "\033[2J\033[H";
	std::cout<<"#######################"<<std::endl;
	std::cout<<"#       Welcome       #"<<std::endl;
	std::cout<<"#         to          #"<<std::endl;
	std::cout<<"#        your         #"<<std::endl;
	std::cout<<"#      PhoneBook      #"<<std::endl;
	std::cout<<"#######################"<<std::endl;
	std::cout<<std::endl;
	std::cout<<str<<std::endl;
}

void AddContact(PhoneBook pb)
{
	(void) pb;
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
}
