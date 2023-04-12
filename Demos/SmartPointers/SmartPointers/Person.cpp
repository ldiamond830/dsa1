#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()
{
	name = "Person";
}

Person::~Person()
{
	cout << "Destructor for " << name << endl;
}

void Person::PrintName()
{
	cout << name << endl;
}
