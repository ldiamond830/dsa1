// RuleOf3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Rule of three: 
//1.Destructor to delete anything stored on the heap
//2.Copy Constructor
//3. Copy Assignment opperator
//need to be implimented for every class that has data on the heap

#include <iostream>
#include "Player.h"
using namespace std;

void wrapper();
int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks()) 
    {
        cout << "leaks";
    }
}

void wrapper() 
{
    Player* p1 = new Player(4, 5, 6);
    p1->PrintInventory();

    //uses dereferenced pointer rather than pointer itself
    Player* p2 = new Player(*p1);
    p2->PrintInventory();

    //p1 = p2; error because = operator will call delete inventory which then gets called again by the destructor
    *p1 = *p2; // this works

    Player sPlayer = Player();
    sPlayer.PrintInventory();

    Player copyPlayer = Player(sPlayer);
    copyPlayer.PrintInventory();


    sPlayer = copyPlayer;
    sPlayer.PrintInventory();
    copyPlayer.PrintInventory();


    delete p1;
    p1 = nullptr;

    delete p2;
    p2 = nullptr;
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
