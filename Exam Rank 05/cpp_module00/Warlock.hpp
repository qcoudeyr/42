#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>

class Warlock {

	public:
		Warlock(const std::string &name, const std::string &title) : _name(name), _title(title) {
			std::cout << _name << ": This looks like another boring day.\n";
		};

		~Warlock() {
			std::cout << _name << ": My job here is done!\n";
		};

		std::string const &getName() const {
			return this->_name;
		};

		std::string const &getTitle() const {
			return this->_title;
		};

		void setTitle(std::string const &title) {
			this->_title = title;
		};

		void introduce() const {
			std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
		};

	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &rhs);

};
#endif
