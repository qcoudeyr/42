#include "Command.hpp"
#include <iostream> // For std::cout in execute()

// Default constructor
Command::Command() : commandType(""), parameters() {}

// Parameterized constructor
Command::Command(const std::string& type, const std::vector<std::string>& params)
	: commandType(type), parameters(params) {}

// Copy constructor
Command::Command(const Command& other)
	: commandType(other.commandType), parameters(other.parameters) {}

// Destructor
Command::~Command() {}

// Assignment operator
Command& Command::operator=(const Command& other) {
	if (this != &other) {
		commandType = other.commandType;
		parameters = other.parameters;
	}
	return *this;
}

std::string Command::getPrefix() const {
    return prefix;
}

std::string Command::getCommand() const {
    return command;
}

std::string Command::getCmdParameters() const {
    return cmd_parameters;
}

std::string Command::getTrailing() const {
    return trailing;
}

void Command::setPrefix(const std::string& newPrefix) {
    prefix = newPrefix;
}

void Command::setCommand(const std::string& newCommand) {
    command = newCommand;
}

void Command::setCmdParameters(const std::string& newCmdParameters) {
    cmd_parameters = newCmdParameters;
}

void Command::setTrailing(const std::string& newTrailing) {
    trailing = newTrailing;
}


// Get command type
std::string Command::getCommandType() const {
	return commandType;
}

// Get parameters
std::vector<std::string> Command::getParameters() const {
	return parameters;
}

// Set command type
void Command::setCommandType(const std::string& type) {
	commandType = type;
}

// Set parameters
void Command::setParameters(const std::vector<std::string>& params) {
	parameters = params;
}

// Execute command
void Command::execute() {
	std::cout << "Executing command: " << commandType << std::endl;
	for (size_t i = 0; i < parameters.size(); ++i) {
		std::cout << "Parameter " << (i + 1) << ": " << parameters[i] << std::endl;
	}
}

bool	check_cmd(const std::string cmd)
{
	if (cmd == "KICK" || cmd == "INVITE" || cmd == "TOPIC" || cmd == "MODE")
		return true;
	else
		return false;
}


void    Command::printParsedTokens(void){
	std::cout << "Prefix: " << this->prefix << std::endl;
	std::cout << "Command: " << this->command << std::endl;
	std::cout << "Cmd_param: " << this->cmd_parameters << std::endl;
	std::cout << "Trailing: " << this->trailing << std::endl;
}

//TODO fix the problem if we spam space then it can find many components
// also be able to not put space after t    he colon (for now it creates a problem with the prefix)

void Command::parser(std::string input) {
	// Split the input string based on spaces and colon
	std::vector<std::string> components = splitString(input, ' ');
	if (components.size() < 4) {
		std::cout << CL_RED << "[!] Error: command incomplete." << RESET << std::endl;
		return;
	}
	size_t colon_pos = components[0].find(':');
	this->prefix = components[1];
	this->command = components[2];
	if (check_cmd(this->command) == false)
	{
		std::cout << CL_RED << "[!] " << RESET << "Error: This command does not exist." << RESET << std::endl;
		return;
	}
	this->cmd_parameters = components[3];
	// Find the position of the colon in the original input
	size_t trailing_pos = input.find(':', colon_pos + 1);
	if (trailing_pos != std::string::npos) {
		// Trailing is everything after the last colon
		this->trailing = input.substr(trailing_pos + 1);
	}
	printParsedTokens();
}

std::vector<std::string> Command::splitString(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}
