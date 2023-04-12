#include "Fighter.h"
#include <iostream>
using namespace std;
Fighter::Fighter()
{
	weaponSkill = "Parry";
}

Fighter::Fighter(std::string _name, std::string _weaponSkill, int _health, int _strength, int _dexterity) : Player(_name, _health, _strength, _dexterity)
{
	weaponSkill = _weaponSkill;

}

void Fighter::printFighter()
{
	Player::printPlayer();
	cout << "Weapon Skill: " << weaponSkill << endl;
}
