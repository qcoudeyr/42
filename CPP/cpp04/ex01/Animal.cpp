#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const & base) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = base;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const & base) {
	if (this != &base)
		this->_type = base.getType();
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "*silence*" << std::endl;
}
