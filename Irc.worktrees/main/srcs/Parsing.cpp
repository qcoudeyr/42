#include "Parsing.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Parsing::Parsing()
{
}

Parsing::Parsing( const Parsing & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Parsing::~Parsing()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Parsing &				Parsing::operator=( Parsing const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Parsing const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */