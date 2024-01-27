#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	private:

	public:
		Dog();
		Dog(Dog const & base);
		~Dog();

		Dog& operator=(Dog const & base);

		void makeSound() const;
};

#endif