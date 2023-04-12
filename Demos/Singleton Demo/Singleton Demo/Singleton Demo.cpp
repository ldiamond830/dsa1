// Singleton Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enemy.h"
#include "Chest.h"
#include "PointSystem.h"
int main()
{
    //servers same function
    //PointSystem* ps = PointSystem::GetInstance();
    PointSystem::GetInstance()->PrintPointTotal();

    Enemy e1 = Enemy();
    e1.DamageEnemy(3);
    e1.DamageEnemy(20);

    Enemy e2 = Enemy("Zombie", 5, 3);
    e2.DamageEnemy(10);

    Chest c1 = Chest();
    Chest c2 = Chest("Binky's wand", 100);
    c1.OpenChest();
    c2.OpenChest();

    PointSystem::GetInstance()->PrintPointTotal();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
