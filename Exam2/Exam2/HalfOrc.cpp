#include "HalfOrc.h"
#include <iostream>
using namespace std;
void HalfOrc::Display()
{
	//states this is a half orc
	cout << "This half orc is at ";
	//prints position
	MovableObject::Display();
}
