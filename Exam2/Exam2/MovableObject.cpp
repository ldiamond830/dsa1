#include "MovableObject.h"
#include <iostream>

using namespace std;
MovableObject::~MovableObject()
{
}
//sets the xPosition and yPosition variables to the parameter values
void MovableObject::SetPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

void MovableObject::Display()
{
	//prints the x and y position of the object to the console
	cout << "X: " << xPosition << ", Y: " << yPosition << endl;
}
