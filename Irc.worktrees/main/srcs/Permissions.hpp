#ifndef PERMISSIONS_HPP
#define PERMISSIONS_HPP


#include <map>
#include <iostream>
#include <string>
#include "Main.hpp"

class Permissions {
public:
	// Orthodox Canonical Form
	Permissions(); // Default constructor
	Permissions(const Permissions& other); // Copy constructor
	~Permissions(); // Destructor
	Permissions& operator=(const Permissions& other); // Assignment operator

	// Method
	bool checkPermission(const std::string& user, const std::string& permission) const;

	// Setters
	void setPermission(const std::string& user, const std::string& permission);
	void removePermission(const std::string& user);

private:
	std::map<std::string, std::string> userPermissions;
};

std::ostream &			operator<<( std::ostream & o, Permissions const & i );

#endif /* ***************************************************** PERMISSIONS_H */
