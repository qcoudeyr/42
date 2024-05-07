#include "Authentication.hpp"

// Default constructor
Authentication::Authentication() {}

// Copy constructor
Authentication::Authentication(const Authentication& other) : userDatabase(other.userDatabase) {}

// Destructor
Authentication::~Authentication() {}

// Assignment operator
Authentication& Authentication::operator=(const Authentication& other) {
	if (this != &other) {
		userDatabase = other.userDatabase;
	}
	return *this;
}

// Methods
bool Authentication::authenticateUser(const std::string& username, const std::string& password) {
	if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
		return true;
	}
	return false;
}

void Authentication::registerUser(const std::string& username, const std::string& password) {
	userDatabase[username] = password;
}
