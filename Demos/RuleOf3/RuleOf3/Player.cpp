#include "Player.h"
#include <iostream>
#include <algorithm>
using namespace std;

Player::Player() : Player(1,2,3)
{
	cout << "Default Constrcutor" << endl;
}

Player::Player(int item1, int item2, int item3)
{
	cout << "Param Constrcutor" << endl;

	invSize = 3;
	inventory = new int[invSize] {item1, item2, item3};

}

Player::~Player()
{
	cout << "destructor" << endl;
	delete[] inventory;
	//not strictly necessary
	inventory = nullptr;
}

Player::Player(const Player& other)
{
	cout << "Copy Constructor" << endl;
	invSize = other.invSize;
	inventory = new int[invSize];

	copy(other.inventory, other.inventory + other.invSize, inventory);

}

Player& Player::operator=(const Player& other)
{
	//if trying to set a player equal to itself
	if (this == &other) 
	{
		return *this;
	}

	//cleans up memory currently being used
	if (inventory != nullptr) {
		delete[] inventory;
		inventory = nullptr;
		invSize = 0;
	}

	//copies over all values
	invSize = other.invSize;
	inventory = new int[invSize];

	copy(other.inventory, other.inventory + other.invSize, inventory);

	return *this;

}

void Player::PrintInventory()
{
	for (unsigned short i = 0; i < invSize; i++)
	{
		cout << inventory[i] << ", ";
	}

	cout << "Which is stored at: " << inventory << endl;
}
