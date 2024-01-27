/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:48:18 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/27 16:53:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal, public Brain
{
private:
	Brain *brain;
public:
	Cat();
	~Cat();
	Cat(Cat const & base);
	Cat& operator=(Cat const & base);
	void setIdeas(std::string str);
	Brain *getBrain() const;
	Brain *setIdeas() const;
	void makeSound() const;
};

#endif
