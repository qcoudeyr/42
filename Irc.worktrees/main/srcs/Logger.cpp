#include "Logger.hpp"
#include "Main.hpp"

// Default constructor
Logger::Logger() : logLevel("info") {}

// Copy constructor
Logger::Logger(const Logger& other) : logLevel(other.logLevel) {
	logFile.open("log.txt", std::ios::app);
}

// Destructor
Logger::~Logger() {
	if (logFile.is_open()) {
		logFile.close();
	}
}

// Assignment operator
Logger& Logger::operator=(const Logger& other) {
	if (this != &other) {
		logLevel = other.logLevel;
	}
	return *this;
}

// Additional constructor for initializing members
Logger::Logger(const std::string& filename) {
	logFile.open(filename.c_str(), std::ios::app);
	if (!logFile.is_open()) {
		throw std::runtime_error("Unable to open log file.");
	}
	else
		std::cout << CL_RED << "\e[3m" << "Start saving log into server.log file" << "\e[0m" << std::endl;
}

// Method
void Logger::logMessage(const std::string& message) {
	struct timeval time_now;
	gettimeofday(&time_now, NULL);  // Get the current time
	time_t now_seconds = time_now.tv_sec;
	struct tm *timeinfo = localtime(&now_seconds);

	// Prepare the time string
	char time_str[20];
	strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);

	// Append microseconds
	char current_time[40];
	sprintf(current_time, "%s.%06ld", time_str, time_now.tv_usec);

	// Write to log file
	if (logFile.is_open()) {
		logFile << current_time << " - " << message << std::endl;
	}
	std::cout << CL_RED << "\e[3m\t" << message << "\e[0m" << std::endl;
}
