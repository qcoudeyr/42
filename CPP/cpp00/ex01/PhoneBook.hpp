/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:58:36 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 14:01:12 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK.HPP
#define PHONEBOOK.HPP

#include "Contact.hpp"
class PhoneBook
{
private:
	Contact _contacts[8];
public:
	void	MenuHeader(std::string str);
};

#endif
