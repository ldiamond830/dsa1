#pragma once
#include <string>
class Enemy
{
public:
	Enemy();
	Enemy(std::string _type, int _health, int _pointValue);

	void DamageEnemy(int _damage);

private:
	std::string type;
	int health;
	int pointValue;
};

