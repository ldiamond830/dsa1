#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	cout << "player default constructor" << endl;

	name = "Binky";
	invSize = 4;
	inventory = new short[invSize];

	for (unsigned short i = 0; i < invSize; i++) {
		inventory[i] = rand() % 100;
	}
}

Player::~Player()
{
	cout << "Player Destructor" << endl;


	delete[] inventory;
	inventory = nullptr;
}

void Player::PrintInventory()
{
	cout << "Player: " << name << endl;
	cout << "Inventory: ";
	for (unsigned short i = 0; i < invSize; i++) {
		cout << inventory[i] << ", ";
	}
	cout << endl;
}
