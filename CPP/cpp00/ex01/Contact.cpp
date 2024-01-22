/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:37:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 13:58:54 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"



Contact::Contact(){
}

Contact::~Contact(){
}

std::string	Contact::get_firstName() const
{
	return (this->_firstName);
}
std::string	Contact::get_lastName() const
{
	return (this->_lastName);
}
std::string	Contact::get_nickname() const
{
	return (this->_nickname);
}
std::string	Contact::get_phoneNumber() const
{
	return (this->_phoneNumber);
}
std::string	Contact::get_darkestSecret() const
{
	return (this->_darkestSecret);
}

void	Contact::set_firstName(std::string input)
{
	this->_firstName = input;
}
void	Contact::set_lastName(std::string input)
{
	this->_lastName = input;
}
void	Contact::set_nickname(std::string input)
{
	this->_nickname = input;
}
void	Contact::set_phoneNumber(std::string input)
{
	this->_phoneNumber = input;
}
void	Contact::set_darkestSecret(std::string input)
{
	this->_darkestSecret = input;
}
