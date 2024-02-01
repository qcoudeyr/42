#pragma once
#include "ATarget.hpp"
#include <iostream>

class ATarget;
class ASpell{
    public:
        ASpell(std::string name, std::string effects) : _name(name), _effects(effects){};
        virtual ~ASpell(){};
        ASpell(ASpell const &src){
            *this = src;
        };
        ASpell & operator=(ASpell const &src){
            this->_name = src.getName();
            this->_effects = src.getEffects();
            return (*this);
        };
        std::string getName() const{
            return this->_name;
        };
        std::string getEffects() const{
            return this->_effects;
        };
        virtual ASpell *clone() const = 0;
        void launch(ATarget const &t) const;
    protected:
        std::string _name;
        std::string _effects;
};
