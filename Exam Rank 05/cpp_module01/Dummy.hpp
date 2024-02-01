#pragma once

#include "ATarget.hpp"
#include <iostream>

class Dummy : public ATarget{
public:
	Dummy() : ATarget("Target Practice Dummy") {}
	~Dummy() {}

	ATarget* clone() const {
		return new Dummy();
	}
};
