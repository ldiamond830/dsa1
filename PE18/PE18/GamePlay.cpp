#include "GamePlay.h"
#include <iostream>
GamePlay::GamePlay(std::string _name)
{
	name = _name;
}

void GamePlay::Update()
{
	for (short i = 1; i <= 10; i++)
	{
		std::cout << name << ": " << i * 10 << "% complete" << std::endl;
	}
	
}
