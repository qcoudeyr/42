#include "ATarget.hpp"

void    ATarget::getHitBySpell(ASpell const & s) const {
    std::cout << this->getType() << " has been " << s.getEffects() << "!" << std::endl;
}
