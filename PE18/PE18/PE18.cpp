// PE18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "NumberPrinter.h"
#include <vector>
#include "GamePlay.h"
using namespace std;
int main()
{
	vector<thread> threadList;
	
	//having a higher thread count leads the output to be more scrambled since there are a greater number of threads running at the same time when cout can only print 1 value at a time 
	for (short i = 0; i < 50; i++)
	{
		NumberPrinter numPrinter = NumberPrinter(i);
		//numPrinter.Print();
		threadList.push_back(thread(&NumberPrinter::Print, numPrinter));
		
	}

	for (short i = 0; i < threadList.size(); i++)
	{
		//rejoins each thread to prevent an abort
		threadList[i].join();
	}


	//part 2
	//creating objects
	GamePlay gamePlay1("Phsyics");
	GamePlay gamePlay2("Models");
	GamePlay gamePlay3("Textures");
	GamePlay gamePlay4("Particle Effects");
	GamePlay gamePlay5("Player");

	vector<thread*> gamePlayThreads;
	//creating the new threads
	gamePlayThreads.push_back(new thread(&GamePlay::Update, gamePlay1));
	gamePlayThreads.push_back(new thread(&GamePlay::Update, gamePlay2));
	gamePlayThreads.push_back(new thread(&GamePlay::Update, gamePlay3));
	gamePlayThreads.push_back(new thread(&GamePlay::Update, gamePlay4));
	gamePlayThreads.push_back(new thread(&GamePlay::Update, gamePlay5));

	

	for (short i = 0; i < 5; i++)
	{
		//rejoins each thread to have the main thread wait until all of the gamePlayThreads are complete before continuing
		gamePlayThreads[i]->join();
	}

	//once each gamePlayThread has run prints update complete
	cout << "Update Complete" << endl;
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
