#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <string>

class File {
public:
	// Orthodox Canonical Form
	File(); // Default constructor
	File(const File& other); // Copy constructor
	~File(); // Destructor
	File& operator=(const File& other); // Assignment operator

	// Additional constructor for initializing members
	File(const std::string& fileName, const std::string& fileType);

	// Getters
	std::string getFileName() const;
	std::string getFileType() const;
	long getFileSize() const;

	// File operations
	void open();
	void close();
	std::string read();
	void write(const std::string& data);

private:
	std::string fileName;
	std::string fileType;
	std::fstream fileStream;
	long fileSize;
};

#endif // FILE_HPP
