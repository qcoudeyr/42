#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* carglass = new WrongAnimal();
	const WrongAnimal* feuvert = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << feuvert->getType() << " " << std::endl;
	carglass->makeSound();
	feuvert->makeSound();

	delete meta;
	delete j;
	delete i;
	delete carglass;
	delete feuvert;

	return 0;
}
