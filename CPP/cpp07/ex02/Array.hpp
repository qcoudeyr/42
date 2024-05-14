#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <stdexcept>

template<typename T>
class Array {
private:
	T *data;
	unsigned int size_;

public:
	// Default constructor
	Array() : data(NULL), size_(0) {}

	// Constructor with size parameter
	explicit Array(unsigned int n) : size_(n) {
		data = new T[size_];
		for (unsigned int i = 0; i < size_; ++i) {
			data[i] = T();
		}
	}

	// Copy constructor
	Array(const Array& other) : size_(other.size_) {
		data = new T[size_];
		for (unsigned int i = 0; i < size_; ++i) {
			data[i] = other.data[i];
		}
	}

	// Assignment operator
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] data;
			size_ = other.size_;
			data = new T[size_];
			for (unsigned int i = 0; i < size_; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	// Destructor
	~Array() {
		delete[] data;
	}

	// Subscript operator for element access
	T& operator[](unsigned int index) {
		if (index >= size_) {
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	// Size function
	unsigned int size() const {
		return size_;
	}
};

#endif /* *********************************************************** ARRAY_H */
