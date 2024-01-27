#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal, public Brain
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const & base);
		~Cat();

		Cat& operator=(Cat const & base);

		void makeSound() const;
};

#endif
