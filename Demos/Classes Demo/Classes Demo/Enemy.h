#pragma once
#include "GamePiece.h"
class Enemy :
    public GamePiece
{
public:
    Enemy();
    Enemy(const char* _name, int _damage);

    ~Enemy();

    void Print() override;
    void Attack();

private:
    int damage;

};

