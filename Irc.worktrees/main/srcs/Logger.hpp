#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>

class Server;

class Logger {
public:
	// Orthodox Canonical Form
	Logger(); // Default constructor
	Logger(const Logger& other); // Copy constructor
	~Logger(); // Destructor
	Logger& operator=(const Logger& other); // Assignment operator

	// Additional constructor for initializing members
	Logger(const std::string& filename);

	// Method
	void logMessage(const std::string& message);

private:
	std::ofstream logFile;
	std::string logLevel;
};

std::ostream &			operator<<( std::ostream & o, Logger const & i );

#endif /* ********************************************************** LOGGER_H */
#include <sys/time.h>
