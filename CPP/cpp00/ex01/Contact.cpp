/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:37:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 23:39:21 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

std::string	Contact::get_FirstName() const
{
	return (this->_FirstName);
}
std::string	Contact::get_LastName() const
{
	return (this->_LastName);
}
std::string	Contact::get_NickName() const
{
	return (this->_NickName);
}
std::string	Contact::get_PhoneNumber() const
{
	return (this->_PhoneNumber);
}
std::string	Contact::get_DarkestSecret() const
{
	return (this->_DarkestSecret);
}

void	Contact::set_FirstName(std::string input)
{
	this->_FirstName = input;
}
void	Contact::set_LastName(std::string input)
{
	this->_LastName = input;
}
void	Contact::set_NickName(std::string input)
{
	this->_NickName = input;
}
void	Contact::set_PhoneNumber(std::string input)
{
	this->_PhoneNumber = input;
}
void	Contact::set_DarkestSecret(std::string input)
{
	this->_DarkestSecret = input;
}
