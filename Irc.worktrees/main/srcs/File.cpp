#include "File.hpp"
#include <iostream>

// Default constructor
File::File() : fileName(""), fileType(""), fileSize(0) {}

// Copy constructor
File::File(const File& other)
	: fileName(other.fileName), fileType(other.fileType), fileSize(other.fileSize) {
	if (other.fileStream.is_open()) {
		fileStream.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::binary);
	}
}

// Destructor
File::~File() {
	close();
}

// Assignment operator
File& File::operator=(const File& other) {
	if (this != &other) {
		fileName = other.fileName;
		fileType = other.fileType;
		fileSize = other.fileSize;
		if (other.fileStream.is_open()) {
			fileStream.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::binary);
		}
	}
	return *this;
}

// Additional constructor for initializing members
File::File(const std::string& fileName, const std::string& fileType)
	: fileName(fileName), fileType(fileType), fileSize(0) {}

// Getters
std::string File::getFileName() const { return fileName; }
std::string File::getFileType() const { return fileType; }
long File::getFileSize() const { return fileSize; }

// File operations
void File::open() {
	fileStream.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::binary);
	if (!fileStream) {
		std::cerr << "Failed to open file: " << fileName << std::endl;
		return;
	}
	fileStream.seekg(0, std::ios::end);
	fileSize = fileStream.tellg();
	fileStream.seekg(0, std::ios::beg);
}

void File::close() {
	if (fileStream.is_open()) {
		fileStream.close();
	}
}

std::string File::read() {
	std::string data;
	if (fileStream.is_open()) {
		fileStream.seekg(0, std::ios::beg);
		data.assign((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	}
	return data;
}

void File::write(const std::string& data) {
	if (fileStream.is_open()) {
		fileStream.write(data.c_str(), data.size());
	}
}
