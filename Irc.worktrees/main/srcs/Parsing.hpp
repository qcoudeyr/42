#ifndef PARSING_HPP
# define PARSING_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <sstream>

class Parsing {
    public:
        Pars();
        ~Pars();
        bool parseConfigFile(const std::string& filename);
        void displayData();
    protected:
        size_t port;
        std::string host;
        std::string path;
};

class Parsing
{

	public:

		Parsing();
		Parsing( Parsing const & src );
		~Parsing();

		Parsing &		operator=( Parsing const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Parsing const & i );

#endif /* ********************************************************* PARSING_H */
