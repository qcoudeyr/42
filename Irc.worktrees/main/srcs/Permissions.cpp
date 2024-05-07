#include "Permissions.hpp"

// Default constructor
Permissions::Permissions() {}

// Copy constructor
Permissions::Permissions(const Permissions& other) : userPermissions(other.userPermissions) {}

// Destructor
Permissions::~Permissions() {}

// Assignment operator
Permissions& Permissions::operator=(const Permissions& other) {
	if (this != &other) {
		userPermissions = other.userPermissions;
	}
	return *this;
}

// Method
bool Permissions::checkPermission(const std::string& user, const std::string& permission) const {
	std::map<std::string, std::string>::const_iterator it = userPermissions.find(user);
	if (it != userPermissions.end() && it->second == permission) {
		return true;
	}
	return false;
}

// Setters
void Permissions::setPermission(const std::string& user, const std::string& permission) {
	userPermissions[user] = permission;
}

void Permissions::removePermission(const std::string& user) {
	userPermissions.erase(user);
}
