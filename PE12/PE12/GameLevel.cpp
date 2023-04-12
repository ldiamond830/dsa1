#include "GameLevel.h"
#include <iostream>
using namespace std;
GameLevel::GameLevel()
{
	cout << "Game Level Constructor" << endl;
	numChests = 3;
	exits = 5;
	levelName = "Dungeons";
	enemyList.push_back("Skeleton");
}

GameLevel::~GameLevel()
{
	cout << "Game Level Destructor" << endl;
}
