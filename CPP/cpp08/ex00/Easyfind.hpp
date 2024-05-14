#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <stdexcept>


template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		if (*it == value) {
			return it;
		}
	}
	throw std::runtime_error("Value not found in container");
}

#endif /* ******************************************************** EASYFIND_H */
