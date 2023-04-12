// PE9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;
void wrapper();

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks()) {
        cout << "Leak" << endl;
    }


}
void wrapper() {
    /* PE9
    //creating players on stack without using new keyword
    Player stackPlayerDefault = Player();
    Player stackPlayerParameter = Player("Name", 1, 2, 3);

    Player* heapPlayerDefault = new Player();
    Player* heapPlayerParameter = new Player("Different Name", 4, 5, 6);


    stackPlayerDefault.printPlayer();
    stackPlayerParameter.printPlayer();
    heapPlayerDefault->printPlayer();
    heapPlayerParameter->printPlayer();

    //deleting data off the heap
    delete heapPlayerDefault;
    heapPlayerDefault = nullptr;
    delete heapPlayerParameter;
    heapPlayerParameter = nullptr;
    */
    Fighter* defaultFighter = new Fighter();
    Fighter* paramFighter = new Fighter("Vague Name", "Lightning Bolt", 20, 30, 40);

    defaultFighter->printFighter();
    paramFighter->printFighter();

    delete defaultFighter;
    delete paramFighter;

    cout << endl;

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
