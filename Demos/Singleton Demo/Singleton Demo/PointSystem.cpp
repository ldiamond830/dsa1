#include "PointSystem.h"
#include <iostream>
using namespace std;


PointSystem::PointSystem()
{
	cout << "creating new pointSystem" << endl;
	points = 0;
}

PointSystem* PointSystem::GetInstance()
{
	cout << "Get Instance Call" << endl;
	//static variables can only be created once, consecutive calls will just find it's location in memory
	static PointSystem instance = PointSystem();
	//IF no point system exists create one and return a pointer
	

	//otherwise just return a pointer to the existing point system




	return &instance;
}

void PointSystem::AddPoints(int _changeInPoints)
{
	points += _changeInPoints;
}

void PointSystem::PrintPointTotal()
{
	cout << "current point total: " << points << endl;
}
