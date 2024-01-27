#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"


class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const & base);
		virtual ~Animal();

		Animal& operator=(Animal const & base);

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
