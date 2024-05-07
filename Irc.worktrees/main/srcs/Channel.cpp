#include "Channel.hpp"
#include <algorithm> // For std::find_if
#include <iostream> // For std::cout

// Default constructor
Channel::Channel() : channelName(""), topic("") {}

// Copy constructor
Channel::Channel(const Channel& other)
	: channelName(other.channelName), topic(other.topic), users(other.users), permissions(other.permissions) {}

// Destructor
Channel::~Channel() {}

// Assignment operator
Channel& Channel::operator=(const Channel& other) {
	if (this != &other) {
		channelName = other.channelName;
		topic = other.topic;
		users = other.users;
		permissions = other.permissions;
	}
	return *this;
}

// Getters
std::string Channel::getChannelName() const { return channelName; }
std::string Channel::getTopic() const { return topic; }
std::vector<User*> Channel::getUsers() const { return users; }
std::map<std::string, std::string> Channel::getPermissions() const { return permissions; }

// Setters
void Channel::setChannelName(const std::string& name) { channelName = name; }
void Channel::setTopic(const std::string& newTopic) { topic = newTopic; }
void Channel::setPermissions(const std::map<std::string, std::string>& newPermissions) { permissions = newPermissions; }

// Methods
void Channel::broadcastMessage(const std::string& message, const User& sender) {
	for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
		if (*it != &sender) { // Do not send the message back to the sender
			(*it)->sendMessage(message);
		}
	}
}

void Channel::addUser(User& user) {
	users.push_back(&user);
}

void Channel::removeUser(User& user) {
	users.erase(std::remove(users.begin(), users.end(), &user), users.end());
}
