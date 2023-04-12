#pragma once
#include <string>
class Chest

{
public:
	Chest();
	Chest(std::string _contents, int _pointValue);

	void OpenChest();

private:
	std::string contents;
	int pointValue;
};

