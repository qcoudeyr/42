#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {

    public:
        // ASpell(){}
        ASpell(std::string n, std::string e) : _name(n), _effects(e){}
        virtual ~ASpell(){}
        ASpell(ASpell const &src){
            *this=src;
        }
        ASpell & operator=(ASpell const &rhs){
            this->_name=rhs.getName();
            this->_effects=rhs.getEffects();
            return *this;
        }
        std::string const getName() const{
            return this->_name;
        }
        std::string const getEffects() const {
            return this->_effects;
        }
        virtual ASpell* clone() const =0;

        void launch(ATarget const & t) const;

    protected:
        std::string _name;
        std::string _effects;

};
