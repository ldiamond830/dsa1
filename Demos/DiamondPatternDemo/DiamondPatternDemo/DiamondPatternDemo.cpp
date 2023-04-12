// DiamondPatternDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Sorcerer.h"
#include "Cleric.h"
#include "Multiclass.h"
using namespace std;

int main()
{
    Character myCharacter = Character();
    myCharacter.xPos = 5;
    myCharacter.name = "Josh";
    myCharacter.inventory.push_back("Water");
    myCharacter.PrintData();

    cout << endl;

    Sorcerer mySorcerer = Sorcerer();
    mySorcerer.PrintData();

    cout << endl;

    Cleric myCleric = Cleric();
    myCleric.PrintData();
    
    cout << endl;

    vector<Character*> party = vector<Character*>();
    party.push_back(new Character(10, 15, "Austin"));
    party.push_back(new Sorcerer(13, 14, "Patrick"));

    for (unsigned short i = 0, size = party.size(); i < size; i++) 
    {
        party[i]->PrintData();
        cout << endl;
    }

    for (unsigned short i = 0, size = party.size(); i < size; i++)
    {
        party[i] = nullptr;
    }


    Multiclass myMulti = Multiclass();
    myMulti.PrintData();

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
