#include "Cleric.h"
#include <iostream>
using namespace std;
Cleric::Cleric() : Character(0, 0, "Cleric")
{

	cout << "Cleric default constructor" << endl;
	deity = "Binky";
}

Cleric::Cleric(int _xPos, int _yPos, std::string _name, std::string _deity) : Character(_xPos, _yPos, _name)
{
	cout << "Cleric param constructor for " << _name << endl;
	deity = _deity;
}

Cleric::~Cleric()
{
	cout << "Cleric destructor for " << name << endl;
}

void Cleric::PrintData()
{
	Character::PrintData();
	cout << "	Worships: " << deity;
}
