#include "Player.h"
#include <cstring>
#include <iostream>
using namespace std;
Player::Player(const char* _name, int _health, int _strenght, int _dexterity)
{
	//assigns each int variable using parameters
	strength = _strenght;
	dexterity = _dexterity;
	health = _health;
	//populates name using const so that a string literal can be used as a parameter
	int nameSize = strlen(_name) + 1;
	name = new char[nameSize];
	strcpy_s(name, nameSize, _name);
}

Player::Player()
{
	strength = 10;
	health = 10;
	dexterity = 10;
	name = new char[8] {"Unknown"};
}

void Player::printPlayer()
{
	cout << "Name: ";
	int size = strlen(name);
	//iterates through each character refenced by the pointer
	for (int i = 0; i < size; i++) 
	{
		cout << name[i];
	}
	cout << endl;
	//prints other stats
	cout << "Health: " << health << endl;
	cout << "Strength: " << strength << endl;
	cout << "Dexeterity: " << dexterity << endl;
}

Player::~Player()
{
	//deletes memory data off the heap
	delete[] name;
}
