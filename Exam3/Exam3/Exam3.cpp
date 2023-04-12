// Exam3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>;
#include <vector>
#include "Player.h"
using namespace std;

void wrapper();


int main()
{
    wrapper();


    if (_CrtDumpMemoryLeaks()) {
        cout << "leaks";
    }
}

void wrapper() 
{
    //testing constructor and copy constructor
    Player p1 = Player("First Player");
    cout << "Creating p2 from p1 and setting it's name to second player" << endl;
    //uses extra credit copy constructor to replace ChangeName() call
    Player p2 = Player(p1, "Second Player");
    p2.PrintInventory();
    cout << endl;

    //testing swap item
    cout << "Putting item 200 in p1's inventory slot 1" << endl;
    p1.SwapItem(200, 1);
    cout << "Putting item 200 in p1's inventory slot 20" << endl;
    p1.SwapItem(200, 20);

    p1.PrintInventory();
    p2.PrintInventory();

    cout << endl;
    //testing = operator
    cout << "Setting p1 = p2, then printing p1 inventory and p2 inventory" << endl;
    p1 = p2;
    p1.PrintInventory();
    p2.PrintInventory();

    cout << endl;
    cout << "Creating 10 threads to print p2's inventory" << endl;
    //creates vector to hold each of the threads created
    vector<thread> threadList = vector<thread>();
    for(short i =0; i < 10; i++)
    {
        //creates new threads to call print inventory on p2
        threadList.push_back(thread(&Player::PrintInventory, p2));
    }

    for(short i = 0; i < threadList.size(); i++)
    {
        //joins each thread to prevent an abort
        threadList[i].join();
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
