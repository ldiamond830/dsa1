// PE7_Pointers_Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << boss << endl;
	cout << pOne << endl;
	cout << fakeMonster << endl;

	boss->xPos = 10;
	boss->yPos = 15;

	pOne->xPos = 20;
	pOne->yPos = 30;

	fakeMonster->xPos = 1;
	fakeMonster->yPos = 2;


	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	delete boss;
	boss = nullptr;
	delete pOne;
	pOne = nullptr;
	//these lines cause an issue because fakeMonster is pointing to the same data as pOne which was already deleted
	//delete fakeMonster;
	//fakeMonster = nullptr;
	return 0;
}

