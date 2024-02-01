#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {

    public:
        ATarget(){} // prk ??
        ATarget(std::string t) : _type(t){}
        virtual ~ATarget(){}
        ATarget(ATarget const &src){
            *this=src;
        }
        ATarget & operator=(ATarget const &rhs){
            this->_type=rhs.getType();
            return *this;
        }
        std::string const getType() const{
            return this->_type;
        }
        virtual ATarget* clone() const =0;

        void getHitBySpell(ASpell const & s) const;

    protected:
        std::string _type;

};
