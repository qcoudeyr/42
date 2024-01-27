#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(WrongCat const & base);
		virtual ~WrongCat();

		WrongCat& operator=(WrongCat const & base);
		void makeSound() const;
};

#endif