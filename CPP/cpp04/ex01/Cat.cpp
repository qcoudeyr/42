#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & base) : Animal(base)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = base;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
