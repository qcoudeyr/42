#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>
#include "User.hpp" // Assuming User class is defined in User.hpp

class User;

class Channel {
public:
	// Orthodox Canonical Form
	Channel(); // Default constructor
	Channel(const Channel& other); // Copy constructor
	~Channel(); // Destructor
	Channel& operator=(const Channel& other); // Assignment operator

	// Getters
	std::string getChannelName() const;
	std::string getTopic() const;
	std::vector<User*> getUsers() const;
	std::map<std::string, std::string> getPermissions() const;

	// Setters
	void setChannelName(const std::string& name);
	void setTopic(const std::string& topic);
	void setPermissions(const std::map<std::string, std::string>& permissions);

	// Methods
	void broadcastMessage(const std::string& message, const User& sender);
	void addUser(User& user);
	void removeUser(User& user);

private:
	std::string channelName;
	std::string topic;
	std::vector<User*> users;
	std::map<std::string, std::string> permissions; // Permissions for different users
};

#endif // CHANNEL_HPP
