#include "Enemy.h"
#include <iostream>
#include <cstring>
using namespace std;
Enemy::Enemy() : GamePiece(0, 0, "Enemy")
{
	cout << "Enemy Default Constructor" << endl;

	//creates memory leak
	//pieceName = new char[6]{ "Enemy" };
	//instead use param construtor 

	damage = 10;
}

Enemy::Enemy(const char* _name, int _damage) :GamePiece(0, 0, _name)
{
	cout << "Enemy Param Constructor" << endl;
	damage = _damage;
}

Enemy::~Enemy()
{
	cout << "Enemy Destructor for: " << pieceName << endl;
	//gamepiece class deletes pieceName so nothing needs to happen here
}

void Enemy::Print()
{
	GamePiece::Print();
	cout << "	Damage: " << damage << endl;
}

void Enemy::Attack()
{
	cout << pieceName << " strikes out and deals " << damage << " damage!" << endl;
}
