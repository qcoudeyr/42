#ifndef SERVER_HPP
#define SERVER_HPP


#include <iostream>
#include <string>
#include <map>
#include <list>
#include "User.hpp"
#include "Channel.hpp"
#include "Logger.hpp"

class User;
class Channel;

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 2

class Server
{
	private:
		int 					_port;
		int 					_master_socket;
		int 					_backlog;
		std::string 			_password;
		int						_client_socket[MAX_CLIENTS];
		std::map<int, User*>	_connected_clients;
		std::list<User>			_users;
		std::list<Channel>		_channels;
		Logger 					logger;
		int						_message_socket;

		Server(); // Private default constructor

		void	addClient(int socket);
		void	removeClient(int socket);
		void	answerClient(int socket, std::string request);

	public:
		Server(int port, std::string password);
		~Server();

		void init();
		void loop();

		// Accessors
		int 		getPort() const { return _port; }
		int 		getListenSocket() const { return _master_socket; }
		std::string getPassword() const { return _password; }

		// Methods
		void	sendMessageToClient(std::string message);
		void	log(std::string message);
};

std::ostream &			operator<<( std::ostream & o, Server const & i );


#endif /* ********************************************************** SERVER_H */

