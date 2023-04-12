// Classes Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>
#include "Player.h"
#include "GamePiece.h"
#include "Player2.h"
#include "Enemy.h"
using namespace std;

void wrapper();

int main()
{
    srand(time(NULL));

    wrapper();

    cout << "main after wrapper" << endl;

    _CrtDumpMemoryLeaks();
}

void wrapper() {
    /* Monday content
    //declared on stack
    Player myPlayer = Player();

    Player* heapPlayer = new Player();

    myPlayer.PrintInventory();

    heapPlayer->PrintInventory();

    delete heapPlayer;
    heapPlayer = nullptr;

    //works the same as lists in c#
    vector<Player*> players = vector<Player*>();
    for (int i = 0; i < 4; i++) {
        players.push_back(new Player());
    }

    for (int i = 0, size = players.size(); i < size; i++) {
        players[i]->PrintInventory();
        delete players[i];
        players[i] = nullptr;
    }
    */
    GamePiece defaultPiece = GamePiece();
    GamePiece paramPiece = GamePiece(10, 4, "Josh");

    defaultPiece.Print();
    paramPiece.Print();

    Player2 defaultPlayer = Player2();
    Player2 paramPlayer = Player2(-10, 20, "Binky", 1000000);

    defaultPlayer.Print();
    paramPlayer.Print();

    cout << endl << "ENEMIES" << endl;

    Enemy defaultEnemy = Enemy();


    cout << "end of wrapper" << endl;

    Enemy defaultEnemy = Enemy();
    Enemy paramEnemy = Enemy("Napalm", 1000000);


     defaultEnemy.Print();
     paramEnemy.Print();

     defaultEnemy.Attack();
     paramEnemy.Attack();

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
