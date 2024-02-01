#include "ASpell.hpp"

void ASpell::launch(ATarget const & t) const{
    t.getHitBySpell(*this);
}
