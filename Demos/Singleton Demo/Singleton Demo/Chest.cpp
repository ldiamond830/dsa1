#include "Chest.h"
#include <iostream>
#include "PointSystem.h"
using namespace std;
Chest::Chest() : Chest("Some Stuff", 10)
{
}

Chest::Chest(std::string _contents, int _pointValue)
{
	contents = _contents;
	pointValue = _pointValue;
}

void Chest::OpenChest()
{
	cout << "You open the chest. Inside you find: " << contents;
	cout << ". You gain " << pointValue << " Points" << endl;

	PointSystem::GetInstance()->AddPoints(pointValue);
}
