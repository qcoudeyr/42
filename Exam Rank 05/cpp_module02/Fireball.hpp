#pragma once
#include "ASpell.hpp"
#include <iostream>

class Fireball : public ASpell {
    public:
        Fireball():ASpell("Fireball","burnt to a crisp"){}
        ~Fireball(){}
        ASpell* clone() const{
            return new Fireball();
        }
};
