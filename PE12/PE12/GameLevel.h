#pragma once
#include <string>
#include <vector>
class GameLevel
{
public:
	GameLevel();
	~GameLevel();
	
private:
	int exits;
	int numChests;
	std::string levelName;
	std::vector<std::string> enemyList;
};

