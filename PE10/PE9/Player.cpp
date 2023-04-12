#include "Player.h"
#include <cstring>
#include <iostream>
using namespace std;
Player::Player(std::string _name, int _health, int _strenght, int _dexterity)
{
	//assigns each int variable using parameters
	strength = _strenght;
	dexterity = _dexterity;
	health = _health;
	name = _name;
}

Player::Player()
{
	strength = 10;
	health = 10;
	dexterity = 10;
	name = "Unknown";
}

void Player::printPlayer()
{
	cout << "Name: ";
	int size = name.size();
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
	
}
