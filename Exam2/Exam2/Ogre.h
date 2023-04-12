#pragma once
#include "MovableObject.h"
//uses virtual inheritence to prevent issues with halforc having two MovableObjects to inherit from
class Ogre : virtual public MovableObject
{
	//private fields
private:
	int* inventoryIds;
	const int inventorySize = 3;
public:
	//default constructor
	Ogre();
	//destructor
	~Ogre();
	//override methdos
	void Display() override;
};

