/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:06:19 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/05/12 21:21:47 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	int id;
	std::string name;
	double value;
};


class Serializer
{

	public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

};

std::ostream &			operator<<( std::ostream & o, Serializer const & i );

#endif /* ****************************************************** SERIALIZER_H */
