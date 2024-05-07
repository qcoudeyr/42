#include "Server.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

Server::Server(int port, std::string password): _port(port), _master_socket(-1), _backlog(10), _password(password), _connected_clients(), _users(), _channels(), logger("server.log"), _message_socket(-1)
{
	if (port < 1 || port > 65535)
	{
		std::cerr << "Error: port number must be an integer between 1 and 65535" << std::endl;
		throw std::invalid_argument("Invalid port number");
	}
}



Server::~Server()
{
	if (_master_socket != -1)
		close(_master_socket);
	for (std::map<int, User*>::iterator it = _connected_clients.begin(); it != _connected_clients.end(); it++)
	{
		if (it->second != NULL)
			delete it->second;
	}
}

void Server::init()
{
	logger.logMessage("Initializing server...");

	struct sockaddr_in server_addr;

	_master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (_master_socket == -1)
	{
		logger.logMessage("Error: Socket creation failed");
		std::cerr << "Error: Socket creation failed" << std::endl;
		throw std::runtime_error("Socket creation failed");
	}

	int opt = 1;
	if (setsockopt(_master_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
	{
		logger.logMessage("Error: Setsockopt failed");
		std::cerr << "Error: Setsockopt failed" << std::endl;
		throw std::runtime_error("Setsockopt failed");
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(_port);

	if (bind(_master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		logger.logMessage("Error: Socket bind failed");
		std::cerr << "Error: Socket bind failed" << std::endl;
		throw std::runtime_error("Socket bind failed");
	}

	if (listen(_master_socket, _backlog) < 0)
	{
		logger.logMessage("Error: Listen failed");
		std::cerr << "Error: Listen failed" << std::endl;
		throw std::runtime_error("Listen failed");
	}

	logger.logMessage("Server initialized successfully.");
}

void	Server::loop()
{
	int		max_fd;
	int		activity;
	int		new_socket;
	int		i;
	char	buffer[BUFFER_SIZE];
	fd_set	read_fds;
	std::string	answer;

	logger.logMessage("Server main loop started.");
	// Initialize client socket array
	memset(_client_socket, 0, sizeof(_client_socket));

	while (1)
	{
		// Clear the socket set
		FD_ZERO(&read_fds);

		// Add master socket to set
		FD_SET(_master_socket, &read_fds);
		max_fd = _master_socket;

		// Add child sockets to set
		for (i = 0; i < MAX_CLIENTS; i++)
		{
			if (_client_socket[i] > 0)
				FD_SET(_client_socket[i], &read_fds);
			if (_client_socket[i] > max_fd)
				max_fd = _client_socket[i];
		}

		// Wait for an activity on one of the sockets
		logger.logMessage("Waiting for an activity...");
		activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

		if ((activity < 0) && (errno != EINTR))
			std::cerr << "Error: Select error" << std::endl;

		// If something happened on the master socket, then it's an incoming connection
		if (FD_ISSET(_master_socket, &read_fds))
		{
			if ((new_socket = accept(_master_socket, NULL, NULL)) >= 0)
			{
				logger.logMessage("\tNew connection accepted.");
				// Add new socket to array of sockets
				for (i = 0; i < MAX_CLIENTS; i++)
				{
					if (_client_socket[i] == 0)
					{
						_client_socket[i] = new_socket;
						this->addClient(_client_socket[i]);
						break;
					}
				}
			}
		}

		// Else it's some IO operation on some other socket
		for (i = 0; i < MAX_CLIENTS; i++)
	{
			if (FD_ISSET(_client_socket[i], &read_fds))
			{
				int valread = read(_client_socket[i], buffer, BUFFER_SIZE);
				if (valread == 0)
				{
					logger.logMessage("\tClient disconnected.");
					// Someone disconnected, get details and print
					this->removeClient(_client_socket[i]);
					close(_client_socket[i]);
					_client_socket[i] = 0;
				}
				else
				{
					_message_socket = _client_socket[i];
					buffer[valread] = '\0';
					logger.logMessage("\tServer receive from Client :");
					logger.logMessage(buffer);

					// Answer to client
					this->answerClient(_client_socket[i], buffer);

					// Remove socket if client has been disconnected
					if (_connected_clients.find(_client_socket[i]) == _connected_clients.end())
						_client_socket[i] = 0;
				}
			}
		}
	}
}

void	Server::addClient(int socket)
{
	_connected_clients[socket] = NULL;
}

void	Server::removeClient(int socket)
{
	if (_connected_clients[socket] != NULL)
		delete _connected_clients[socket];
	_connected_clients.erase(socket);
}

void	Server::sendMessageToClient(std::string message)
{
	send(_message_socket, message.c_str(), message.size(), 0);
}

void	Server::answerClient(int socket, std::string request)
{
	Command	command;

	command.parser(request);
	if (_connected_clients[socket] == NULL)
	{
		// Disconnect client if first command is not PASS or password is incorrect
		if (command.getCommand() != "PASS" || command.getParameters().front() != _password)
		{
			logger.logMessage("\tWrong password");
			logger.logMessage("\tClient disconnected.");
			if (command.getParameters().empty() != true)
				this->sendMessageToClient(":ft_irc 464 " + command.getParameters().front() + " :Password Incorrect");
			this->sendMessageToClient("ERROR :Closing Link: localhost (Bad Password)");
			this->removeClient(socket);
		}
		// Else connect client to socket
		else
			_connected_clients[socket] = new User;
	}
	else
		_connected_clients[socket]->execute(command, *this);
}

void	Server::log(std::string message)
{
	logger.logMessage(message);
}

/* ************************************************************************** */
