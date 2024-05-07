#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <map>
#include <string>
#include "Server.hpp"
#include "Channel.hpp"
#include "Command.hpp"

// Forward declaration of Channel class to avoid circular dependency
class Channel;
class Server;
class Command;

class User {
public:
	User(); // Default constructor
	User(const User& other); // Copy constructor
	~User(); // Destructor
	User& operator=(const User& other); // Assignment operator

	// Additional constructor for initializing members
	User(const std::string& username, const std::string& nickname);

	// Getters
	std::string getUsername() const;
	std::string getNickname() const;
	std::string getStatus() const;
	Channel* getCurrentChannel() const;

	// Setters
	void setUsername(const std::string& username);
	void setNickname(const std::string& nickname);
	void setStatus(const std::string& status);
	void setCurrentChannel(Channel* channel);

	// Methods
	void sendMessage(const std::string& message);
	void joinChannel(Channel& channel);
	void leaveChannel();
	void execute(Command command, Server &server);

	// Commands
	void nickCommand(Command command, Server &server);

private:
	std::string username;
	std::string nickname;
	std::string status;
	std::string password;
	Channel* currentChannel;

	typedef void (User::*cmd_ptr)(Command, Server &);
	static const std::map<std::string, cmd_ptr> _known_commands;

	static std::map<std::string, cmd_ptr> init_known_commands();
};

#endif // USER_HPP
