#include "Enemy.h"
#include <iostream>
#include "PointSystem.h"
using namespace std;
Enemy::Enemy() : Enemy("Ghoul", 10, 5)
{
}

Enemy::Enemy(std::string _type, int _health, int _pointValue)
{
	type = _type;
	health = _health;
	pointValue = _pointValue;
}

void Enemy::DamageEnemy(int _damage)
{
	health -= _damage;
	cout << "You deal " << _damage << " damage to the " << type << ". ";
	

	if (health <= 0) {
		cout << endl;
		cout << "Enemy " << type << " has died! ";
		cout << "You gain " << pointValue << " points!" << endl;

		PointSystem::GetInstance()->AddPoints(pointValue);
	}
	else {
		cout << "It has " << health << " health left!" << endl;
	}

}
