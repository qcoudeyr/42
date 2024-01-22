/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:37:23 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 13:58:18 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();
	std::string	get_firstName() const;
	std::string	get_lastName() const;
	std::string	get_nickname() const;
	std::string	get_phoneNumber() const;
	std::string	get_darkestSecret() const;
	void	set_firstName(std::string input);
	void	set_lastName(std::string input);
	void	set_nickname(std::string input);
	void	set_phoneNumber(std::string input);
	void	set_darkestSecret(std::string input);
};

#endif
