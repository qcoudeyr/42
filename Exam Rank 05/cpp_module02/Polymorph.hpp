#pragma once
#include "ASpell.hpp"
#include <iostream>

class Polymorph : public ASpell {
    public:
        Polymorph():ASpell("Polymorph","turned into a critter"){}
        ~Polymorph(){}
        ASpell* clone() const{
            return new Polymorph();
        }
};
