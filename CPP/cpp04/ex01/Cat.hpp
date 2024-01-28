/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:18 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/28 13:38:23 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal
{
private:
	Brain *brain;
public:
	Cat();
	~Cat();
	Cat(const Cat & base); // Note the use of 'const Cat&'
	Cat& operator=(const Cat & base);
	void setIdeas(std::string str);
	Brain *getBrain() const;
	void makeSound() const;
};

#endif
