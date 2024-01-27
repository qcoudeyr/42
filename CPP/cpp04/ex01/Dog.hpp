/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 17:24:57 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal
{
private:
	Brain* brain;
public:
	Dog();
	~Dog();
	Dog(Dog const & base);
	Dog& operator=(Dog const & base);

	void setIdeas(std::string str);
	Brain* getBrain() const;
	void makeSound() const;
};

#endif
