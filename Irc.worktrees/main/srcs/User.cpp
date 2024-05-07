#include "User.hpp"
#include <iostream>

typedef void (User::*cmd_ptr)(Command, Server &);

std::map<std::string, cmd_ptr> User::init_known_commands()
{
	std::map<std::string, cmd_ptr> known_commands;

	known_commands["NICK"] = &User::nickCommand;

	return (known_commands);
}

const std::map<std::string, cmd_ptr> User::_known_commands = init_known_commands();

// Default constructor
User::User() : username(""), nickname(""), status("offline"), currentChannel(NULL) {}

// Copy constructor
User::User(const User& other)
	: username(other.username), nickname(other.nickname),
	  status(other.status), currentChannel(other.currentChannel) {}

// Destructor
User::~User() {}

// Assignment operator
User& User::operator=(const User& other) {
	if (this != &other) {
		username = other.username;
		nickname = other.nickname;
		status = other.status;
		currentChannel = other.currentChannel;
	}
	return *this;
}

// Additional constructor for initializing members
User::User(const std::string& username, const std::string& nickname)
	: username(username), nickname(nickname), status("offline"), currentChannel(NULL) {}

// Getters
std::string User::getUsername() const { return username; }
std::string User::getNickname() const { return nickname; }
std::string User::getStatus() const { return status; }
Channel* User::getCurrentChannel() const { return currentChannel; }

// Setters
void User::setUsername(const std::string& newUsername) { username = newUsername; }
void User::setNickname(const std::string& newNickname) { nickname = newNickname; }
void User::setStatus(const std::string& newStatus) { status = newStatus; }
void User::setCurrentChannel(Channel* channel) { currentChannel = channel; }

// Methods
void User::sendMessage(const std::string& message) {
	if (currentChannel) {
		currentChannel->broadcastMessage(message, *this);
	} else {
		std::cerr << "User is not in a channel." << std::endl;
	}
}

void User::joinChannel(Channel& channel) {
	if (currentChannel) {
		leaveChannel();
	}
	currentChannel = &channel;
	channel.addUser(*this);
}

void User::leaveChannel() {
	if (currentChannel) {
		currentChannel->removeUser(*this);
		currentChannel = NULL;
	}
}

void User::execute(Command command, Server &server)
{
	std::map<std::string, cmd_ptr>::const_iterator it;

	// Check if the user know the command
	it = _known_commands.find(command.getCommand());
	if (it != _known_commands.end())
	{
		(this->*(it->second))(command, server);
	}
	else
	{
		server.sendMessageToClient(":ft_irc 421 " + this->nickname + " " + command.getCommand() + " :Unknown command");
	}
}

// Commands
void User::nickCommand(Command command, Server &server)
{
	server.log("Executing NICK as " + this->nickname);
	(void)command;
	(void)server;
}