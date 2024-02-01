#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp" // AA

class ASpell;

class Warlock {

    public :
        Warlock(std::string const &na, std::string const &ti) : _name(na), _title(ti){
            std::cout << _name << ": This looks like another boring day.\n";
        }

        ~Warlock(){
            std::cout << _name << ": My job here is done!\n";
        }

        std::string const &getName() const {
            return this->_name;
        }
        std::string const &getTitle() const {
            return this->_title;
        }

        void setTitle(std::string const &t) {
            this->_title  = t;
        }

        void introduce() const {
            std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
        }

        void learnSpell(ASpell* s) {
            _sb.learnSpell(s);
        }

        void forgetSpell(std::string s){
            _sb.forgetSpell(s);
        }
        //AA
        void launchSpell(std::string const &s, ATarget const &t){
            ASpell* as= _sb.createSpell(s);
            if(as)
                as->launch(t);
        }

    private:
        std::string _name;
        std::string _title;
        // std::map<std::string, ASpell*>_sb;
        SpellBook _sb;
        Warlock(){}
        Warlock(Warlock const &src);
        Warlock & operator=(Warlock const &rhs);

};
