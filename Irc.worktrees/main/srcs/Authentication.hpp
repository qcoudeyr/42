#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP


#include <map>
#include <iostream>
#include <string>
#include "Main.hpp"

class Authentication {
public:
	// Orthodox Canonical Form
	Authentication(); // Default constructor
	Authentication(const Authentication& other); // Copy constructor
	~Authentication(); // Destructor
	Authentication& operator=(const Authentication& other); // Assignment operator

	// Methods
	bool authenticateUser(const std::string& username, const std::string& password);
	void registerUser(const std::string& username, const std::string& password);

private:
	std::map<std::string, std::string> userDatabase;
};

std::ostream &			operator<<( std::ostream & o, Authentication const & i );

#endif /* ************************************************** AUTHENTICATION_H */
