#include "Sorcerer.h"
#include <iostream>
using namespace std;
//saves a function calls but requires a little bit of repeated code
Sorcerer::Sorcerer() : Character(0, 0, "Sorcerer")
{
	cout << "Sorcerer default constructor" << endl;
	sorceryPoints = 2;
}

Sorcerer::Sorcerer(int _xPos, int _yPos, std::string _name) : Character(_xPos, _yPos, _name)
{
	cout << "Sorcerer param constructor for " << _name << endl;
	sorceryPoints = 2;
}

Sorcerer::~Sorcerer()
{
	cout << "Sorcerer descrutor for " << name << endl;
}

void Sorcerer::PrintData()
{
	Character::PrintData();
	cout << "	Sorcery Points: " << sorceryPoints;
}
