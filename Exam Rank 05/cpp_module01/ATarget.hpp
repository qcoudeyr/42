#pragma once
#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget {

    protected:
        std::string _type;

    public:
        ATarget() {}

        ATarget(std::string const& t) : _type(t) {}

        ATarget(ATarget const& src) {
            *this=src;
        };

        ATarget& operator=(ATarget const& rhs) {
            this->_type = rhs.getType();
            return *this;
        };

        virtual ~ATarget() {}

        std::string const& getType() const {
            return this->_type;
        }

        virtual ATarget* clone() const = 0;

        void    getHitBySpell(ASpell const & s) const;

};
