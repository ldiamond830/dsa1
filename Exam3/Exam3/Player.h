#pragma once
#include <string>
class Player
{
public:
	Player(std::string _name);
	Player(const Player& other);
	Player(const Player& other, std::string _name);
	~Player();
	Player& operator= (const Player& other);
	void SwapItem(int _itemID, int _slot);
	void PrintInventory();
	void ChangeName(std::string _newName);

private:
	int inventorySize;
	int* inventory;
	std::string name;
};

