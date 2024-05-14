#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>

class MutantStack
{

	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

		MutantStack &		operator=( MutantStack const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, MutantStack const & i );

#endif /* ***************************************************** MUTANTSTACK_H */