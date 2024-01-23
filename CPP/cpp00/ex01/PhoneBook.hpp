/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:36 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/23 12:47:42 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_index;
public:
	PhoneBook();
	~PhoneBook();
	void	MenuHeader(std::string str);
	void	AddContact();
	int		get_NbContact() const;
	void	SearchContact();
	void	set_NbContact(int value);
	void	PrintContact(int i);
};

void	FormatPrint(std::string input);

#endif
