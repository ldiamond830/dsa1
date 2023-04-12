#pragma once
#include "Player.h"
#include <string>
class Fighter :
    public Player
{
private:
    std::string weaponSkill;

public:
    Fighter();
    Fighter(std::string _name, std::string _weaponSkill, int _health, int _strength, int _dexterity);

    void printFighter();
};

