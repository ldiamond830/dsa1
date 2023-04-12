#include "Character.h"
#include <iostream>
using namespace std;
//uses param constructor to set character with default vlaues
Character::Character() : Character(0,0,"Character")
{
	cout << "Character default constructor" << endl;
}

Character::Character(int _xPos, int _yPos, std::string _name)
{
	cout << "Character param constructor for "<< _name << endl;
	xPos = _xPos;
	yPos = _yPos;
	name = _name;

	inventory = vector<string>();
	//adds to end of vector
	inventory.push_back("Cloak");
	inventory.push_back("Torch");
}

Character::~Character()
{
	cout << "Character destructor for " << name << endl;
}

void Character::PrintData()
{
	cout << "Name: " << name;
	cout << "	Position: (" << xPos << ", " << yPos << ")";
	cout << "	Inventory: ";

	for (unsigned short i = 0, size = inventory.size(); i < size; i++) 
	{
		cout << inventory[i] << ", ";
	}
}
