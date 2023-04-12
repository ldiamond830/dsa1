#pragma once
#include "MovableObject.h"
//uses virtual inheritence to prevent issues with halforc having two MovableObjects to inherit from
class Orc : virtual public  MovableObject
{
public:
	//overrides the version from MovableObject
	 void Display() override;
};

