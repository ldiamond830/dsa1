#pragma once
#include "Orc.h"
#include "Ogre.h"
//inherits from both orc and orge
class HalfOrc : public Orc, public Ogre
{
public:
	void Display() override;

};

