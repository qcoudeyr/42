#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & base) : Animal(base)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = base;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
