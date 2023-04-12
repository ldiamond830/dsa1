#include "Item.h"
#include <iostream>
using namespace std;
Item::Item()
{
	name = "default item";
	damage = 1;
	durability = 1;
}

void Item::print()
{
	cout << name << endl;
	cout << "Damage: " << damage << endl;
	cout << "Durability: " << durability << endl;

}
