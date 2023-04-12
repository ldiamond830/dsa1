#pragma once
class Player
{
public:
	Player(const char* _name, int _health, int _strenght,  int _dexterity);

	Player();

	void printPlayer();
	//destructor
	~Player();

private:
	char* name;
	int strength;
	int health;
	int dexterity;

};

