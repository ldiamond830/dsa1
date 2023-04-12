#include "Ogre.h"
#include <iostream>

using namespace std;
Ogre::Ogre()
{
	//creates an array on the heap with sizr inventory size, fills it and then points at it with inventoryIds
	inventoryIds = new int[inventorySize]{ 3, 9, 12 };
}

Ogre::~Ogre()
{
	//deletes the data inventoryIds points to off the heal
	delete[] inventoryIds;
}

void Ogre::Display()
{
	
	//states this is an ogre
	cout << "This Orge is at ";
	//calls Display() from parent class
	MovableObject::Display();
	//creates a line break
	
	//prints the object's inventory
	cout << "Inventory IDs: ";
	for (short i = 0; i < inventorySize; i++)
	{
		cout << inventoryIds[i] << ", ";
	}
	
	//adds a line break
	cout << endl;
}
