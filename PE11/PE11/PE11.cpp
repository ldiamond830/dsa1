// PE11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Sword.h"
#include "Spear.h"
#include "Axe.h"
#include "Shield.h"
#include <vector>
using namespace std;

void wrapper();

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks()) {
        cout << "leak" << endl;
    }
}

void wrapper() {
    Sword* mySword = new Sword();
    Spear* mySpear = new Spear();
    Axe* myAxe = new Axe();
    Shield* myShield = new Shield();

    vector<Item*> items = vector<Item*>();
    items.push_back(mySword);
    items.push_back(mySpear);
    items.push_back(myAxe);
    items.push_back(myShield);
    int size = items.size();
    for (int i = 0; i < size; i++) {
        items[i]->print();
    }


    delete mySword;
    delete mySpear;
    delete myAxe;
    delete myShield;
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
