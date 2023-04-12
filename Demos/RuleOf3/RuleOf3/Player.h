#pragma once
class Player
{
public:
	Player();
	Player(int item1, int item2, int item3);
	~Player();
	//copy constructor
	Player(const Player& other);

	Player& operator= (const Player& other);


	void PrintInventory();

	int* inventory;
	int invSize;


};

