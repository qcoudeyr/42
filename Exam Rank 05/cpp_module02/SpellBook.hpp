#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class SpellBook {

    public :
        SpellBook(){}

        ~SpellBook(){
            std::map<std::string, ASpell*>::iterator it = _sb.begin();
            for(; it != _sb.end(); it++)
                delete it->second;
            _sb.clear();
        }

        void learnSpell(ASpell* s) {
            if(s)
                _sb.insert(std::pair<std::string,ASpell*>(s->getName(),s->clone()));
        }

        void forgetSpell(std::string const &s){
            if(_sb.find(s) != _sb.end()){
                delete _sb.find(s)->second;
                _sb.erase(_sb.find(s));
            }
        }

        ASpell* createSpell(std::string const& s){
            if(_sb.find(s) != _sb.end())
                return _sb[s];
            return NULL;
        }

    private:
        std::map<std::string, ASpell*>_sb;
        SpellBook(SpellBook const &src);
        SpellBook & operator=(SpellBook const &rhs);

};
