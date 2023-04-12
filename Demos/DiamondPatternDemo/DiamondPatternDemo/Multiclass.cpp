#include "Multiclass.h"
#include <iostream>
using namespace std;
Multiclass::Multiclass() : Character(0,0, "Multiclass"), Sorcerer(), Cleric()
{
	cout << "Multiclass default constructor" << endl;
}

//pluging in all the other variables to the Sorcerer and Cleric constructor is less efficient than just assigning them manually
Multiclass::Multiclass(int _xPos, int _yPos, std::string _name, std::string _deity) : Character(_xPos, _yPos, _name), Sorcerer(), Cleric()
{
	cout << "Multiclass param constructor for "<< _name << endl;
	deity = _deity;

}

Multiclass::~Multiclass()
{
	cout << "Multiclass destructor for " << name << endl;
}

void Multiclass::PrintData()
{
	Sorcerer::PrintData();
	cout << "	Worships: " << deity << endl;
}
