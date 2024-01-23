/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 12:17:38 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook(){
}

PhoneBook::~PhoneBook(){
}

int		PhoneBook::get_NbContact() const
{
	return (this->_index);
}

void		PhoneBook::set_NbContact(int value)
{
	this->_index = value;
}



void PhoneBook::MenuHeader(std::string str)
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

void FormatPrint(const std::string input)
{
	if (input.length() < 10)
		std::cout << std::right << std::setw(10) << input;
	else
		std::cout << input.substr(0, 9) << '.';
	std::cout << '|';
}

void PhoneBook::AddContact()
{
	std::string	input;

	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> First Name: ";
	std::cin>>input;
	this->_contacts[this->_index % 8].set_FirstName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> Last Name: ";
	std::cin>>input;
	this->_contacts[this->_index % 8].set_LastName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> NickName: ";
	std::cin>>input;
	this->_contacts[this->_index % 8].set_NickName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> PhoneNumber: ";
	std::cin>>input;
	this->_contacts[this->_index % 8].set_PhoneNumber(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> His darkest Secret: ";
	std::cin>>input;
	this->_contacts[this->_index % 8].set_DarkestSecret(input);
	PhoneBook::set_NbContact(get_NbContact() + 1);
	MenuHeader("Contact Added !");
}

void PhoneBook::SearchContact()
{
	std::string	input;

	MenuHeader("List of Contact:");
	for(int i = 0; i < get_NbContact(); i++)
	{
		std::stringstream ss;
		ss << i;
		FormatPrint(ss.str());
		FormatPrint(this->_contacts[i].get_FirstName());
		FormatPrint(this->_contacts[i].get_LastName());
		FormatPrint(this->_contacts[i].get_NickName());
		std::cout << std::endl;
	}
}
