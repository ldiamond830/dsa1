#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;
Player::Player(std::string _name)
{

    name = _name;
    inventorySize = 3;
    inventory = new int[inventorySize];

    //default item IDs
    inventory[0] = 10;
    inventory[1] = 20;
    inventory[2] = 30;
}

Player::Player(const Player& other)
{
    //sets the values for the new object using those from the object being copied
    inventorySize = other.inventorySize;
    name = other.name;


    //creates and populates the inventory
    inventory = new int[inventorySize];

    for (short i = 0; i < inventorySize; i++) {
        inventory[i] = other.inventory[i];
    }

}

Player::Player(const Player& other, std::string _name)
{
    //sets the values for the new object using those from the object being copied
    inventorySize = other.inventorySize;
    name = _name;


    //creates and populates the inventory
    inventory = new int[inventorySize];

    for (short i = 0; i < inventorySize; i++) {
        inventory[i] = other.inventory[i];
    }


}

Player::~Player()
{
    //deletes the inventory to prevent memory leaks
    delete[] inventory;
    inventory = nullptr;
}

Player& Player::operator=(const Player& other)
{
    //check if the operator is setting the object equal to itself
    if (this == &other) {
        return *this;
    }

    //deletes the prexisting inventory to prevent memory leaks
    if (inventory != nullptr) {
        delete[] inventory;
        inventory = nullptr;

    }

    inventorySize = other.inventorySize;
    name = other.name;

    //creates the new inventory and populates it with the values from the other object 
    inventory = new int[inventorySize];
    for (int i = 0; i < inventorySize; i++)
    {
        inventory[i] = other.inventory[i];
    }

    return *this;
}


void Player::SwapItem(int _itemID, int _slot)
{
    //checks if the inventory slot is availible
    if (_slot > inventorySize - 1) {
        cout << "Error: slot out of range" << endl;
    }
    else {
        //inputs the new item
        inventory[_slot] = _itemID;
    }
}

void Player::PrintInventory()
{
    //states the name of the current player
    cout << name << "'s inventory: ";
    for (short i = 0; i < inventorySize; i++)
    {
        //prints each item in their inventory
        cout << inventory[i] << ", ";
    }
    cout << endl;
}

void Player::ChangeName(std::string _newName)
{
    //resets the name using the method param
    name = _newName;
}
