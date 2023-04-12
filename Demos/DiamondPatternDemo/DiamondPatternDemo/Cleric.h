#pragma once
#include "Character.h"
class Cleric :
    virtual public Character
{
public:
    Cleric();
    Cleric(int _xPos, int _yPos, std::string _name, std::string _deity);
    ~Cleric();

    void PrintData() override;
protected:
    std::string deity;
};

