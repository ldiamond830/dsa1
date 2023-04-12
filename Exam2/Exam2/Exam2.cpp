// Exam2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Exan #2

#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <vector>
#include "MovableObject.h"
#include "Orc.h"
#include "Ogre.h"
#include <stdlib.h>
#include <time.h>
#include "Declarations.h"
#include "HalfOrc.h"
using namespace std;
void wrapper();

int main()
{
    //set random seed 
    srand(time(NULL));

    //wrapper function used to stack out data
    wrapper();

    //memory leaks catch
    if (_CrtDumpMemoryLeaks()) {
        cout << "leaks";
    }
}

void wrapper() 
{
    vector<MovableObject*> movableObjects = vector<MovableObject*>();
 
    //adding pointers objects on heap to list
    movableObjects.push_back(new Orc());
    movableObjects.push_back(new Orc());
    movableObjects.push_back(new Ogre());
    movableObjects.push_back(new Ogre());
    movableObjects.push_back(new Ogre());
    movableObjects.push_back(new HalfOrc());

    //positions each object at a random position between 100 and -110
    for (short i = 0; i < movableObjects.size(); i++) 
    {
        movableObjects[i]->SetPosition(generateRandom(100,-100), generateRandom(100, -100));
    }

    //calls display on each object
    for (short i = 0; i < movableObjects.size(); i++)
    {
        movableObjects[i]->Display();
    }

    //deletes each object and sets the pointers to nullptr
    for (short i = 0; i < movableObjects.size(); i++)
    {
        delete movableObjects[i];
        movableObjects[i] = nullptr;
    }
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
