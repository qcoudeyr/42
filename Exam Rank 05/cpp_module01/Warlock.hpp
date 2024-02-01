#ifndef WARLOCK_HPP
#define WARLOCK_HPP
# include <iostream>
# include "ATarget.hpp"
# include "ASpell.hpp"
# include <map>

class Warlock {

	public:

		Warlock(std::string const &name, std::string const &title) : _name(name), _title(title){
			std::cout << _name << ": This looks like another boring day.\n";
		};

		~Warlock() {
			std::cout << _name << ": My job here is done!\n";
			}

		std::string const &getName() const {
			return this->_name;
		};
		std::string const &getTitle() const {
			return this->_title;
		}
		void setTitle (std::string const &st) {
			this->_title = st;
		};

		void introduce() const{
			std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
		};

		void learnSpell(ASpell *s) {
			if ( s )
				_sb.insert(std::pair<std::string, ASpell*>(s->getName(), s->clone()));
		};

		void forgetSpell(std::string const & s) {
			if(_sb.find(s) != _sb.end()){
				delete _sb.find(s)->second;
				_sb.erase(_sb.find(s));
			}
		};

		void launchSpell(std::string const s, ATarget &t) {
			if(_sb.find(s) != _sb.end())
				_sb[s]->launch(t);
		};


	private:
		std::map<std::string, ASpell*> _sb;

		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &src);
		Warlock & operator=(Warlock const &rhs);

};
#endif
