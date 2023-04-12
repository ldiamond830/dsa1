#include "Orc.h"
#include <iostream>

using namespace std;
void Orc::Display()
{
	//states that this object is an orc
	cout << "This Orc is at:  ";
	//calls the display method from MovableObject
	MovableObject::Display();
	
}
