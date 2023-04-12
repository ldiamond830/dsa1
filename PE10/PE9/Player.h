#pragma once
#include <string>
class Player
{
public:
	Player(std::string _name, int _health, int _strenght,  int _dexterity);

	Player();

	void printPlayer();
	//destructor
	~Player();

private:
	std::string name;
	int strength;
	int health;
	int dexterity;

};

