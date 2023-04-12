#pragma once
#include <string>
#include <vector>
struct Character
{

	Character();
	Character(int _xPos, int _yPos, std::string _name);
	virtual ~Character();

	virtual void PrintData();

	int xPos;
	int yPos;
	std::string name;
	std::vector<std::string> inventory;


};

