#pragma once
#include <string>
struct Item
{
protected:
	std::string name;
	int damage;
	int durability;

public:
	Item();
	void print();

};

