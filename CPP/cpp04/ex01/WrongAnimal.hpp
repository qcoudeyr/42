#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <string.h>
# include <iomanip>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & base);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(WrongAnimal const & base);
		
		std::string getType() const;
		void makeSound() const;
};

#endif