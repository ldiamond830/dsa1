#pragma once
#include "Character.h"
#include <string>
class Sorcerer :
    virtual public Character
{
protected:
    int sorceryPoints;
public:
    Sorcerer();
    Sorcerer(int _xPos, int _yPos, std::string _name);
    ~Sorcerer();

    void PrintData() override;
};

