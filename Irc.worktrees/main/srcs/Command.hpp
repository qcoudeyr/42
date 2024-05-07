#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Main.hpp"
#include <string>
#include <string>
#include <sstream>
#include <vector>

class Command {
public:
	// Constructors
	Command();
	Command(const std::string& type, const std::vector<std::string>& params);
	Command(const Command& other); // Copy constructor

	// Destructor
	~Command();

	// Assignment operator
	Command& operator=(const Command& other);

	// Getters
	std::string getCommandType() const;
	std::vector<std::string> getParameters() const;
    std::string getPrefix() const;
    std::string getCommand() const;
    std::string getCmdParameters() const;
    std::string getTrailing() const;

    // Setters
    void setPrefix(const std::string& newPrefix);
    void setCommand(const std::string& newCommand);
    void setCmdParameters(const std::string& newCmdParameters);
    void setTrailing(const std::string& newTrailing);
	void setCommandType(const std::string& type);
	void setParameters(const std::vector<std::string>& params);

	// Execute command
	void execute();

		//Parsing
	void parser(std::string str);
	std::vector<std::string> splitString(const std::string& str, char delimiter);
	void printParsedTokens(void);


private:
	std::string prefix;
	std::string command;
	std::string cmd_parameters;
	std::string trailing;
	std::string commandType;
	std::vector<std::string> parameters;
};

#endif // COMMAND_HPP
