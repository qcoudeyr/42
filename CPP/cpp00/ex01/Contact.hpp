/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:37:23 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/22 23:33:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

public:
	Contact();
	~Contact();
	std::string	get_FirstName() const;
	std::string	get_LastName() const;
	std::string	get_NickName() const;
	std::string	get_PhoneNumber() const;
	std::string	get_DarkestSecret() const;
	void	set_FirstName(std::string input);
	void	set_LastName(std::string input);
	void	set_NickName(std::string input);
	void	set_PhoneNumber(std::string input);
	void	set_DarkestSecret(std::string input);
};

#endif
