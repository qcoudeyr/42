/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 13:09:33 by  qcoudeyr        ###   ########.fr       */
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
	std::getline(std::cin, input);
	this->_contacts[this->_index % 8].set_FirstName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> Last Name: ";
	std::getline(std::cin, input);
	this->_contacts[this->_index % 8].set_LastName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> NickName: ";
	std::getline(std::cin, input);
	this->_contacts[this->_index % 8].set_NickName(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> PhoneNumber: ";
	std::getline(std::cin, input);
	this->_contacts[this->_index % 8].set_PhoneNumber(input);
	MenuHeader("So you want to add a contact ?\nCan you tell me more about it ?!");
	std::cout<<"$> His darkest Secret: ";
	std::getline(std::cin, input);
	this->_contacts[this->_index % 8].set_DarkestSecret(input);
	PhoneBook::set_NbContact(get_NbContact() + 1);
	MenuHeader("Contact Added !");
}

void PhoneBook::SearchContact()
{
	int	input;

	MenuHeader("List of Contact:");
	FormatPrint("Index");
	FormatPrint("First Name");
	FormatPrint("Last Name");
	FormatPrint("Nick Name");
	std::cout<<std::endl;
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
	std::cout << "Please enter an index to view contact\nOr enter anything else to go back" << std::endl;
	std::cout << "$> ";
	std::cin >> input;
	if (input >= 0 && input <= 7)
		PrintContact(input);
	else
		MenuHeader("Error this index doesn't exist !\n Back to the Menu");
}

void	PhoneBook::PrintContact(int i)
{
	std::string input;

	MenuHeader("");
	std::cout << "First Name: " << this->_contacts[i].get_FirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[i].get_LastName() << std::endl;
	std::cout << "Nick Name: " << this->_contacts[i].get_NickName() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[i].get_PhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[i].get_DarkestSecret() << std::endl;
	std::cout << "Press something than enter to go back!";
	while (input.empty())
		std::cin >> input;
}
