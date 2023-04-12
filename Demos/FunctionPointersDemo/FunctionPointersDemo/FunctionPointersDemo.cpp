// FunctionPointersDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OtherFile.h"
#include <algorithm>
using namespace std;

void helloWorld(int num, int num2);
bool descending(int a, int b);

int main()
{


    helloWorld(5, 16);

    void(*helloPtr)(int, int);
    helloPtr = helloWorld;
    //runs the method
    helloPtr(20, 90);

    runThing(helloWorld, 9, 10);
    runThing(helloPtr, 66, 7);

    const int arraySize = 5;
    int myArray[arraySize] = { 1, 3, 2, 5, 4 };
    //plug in own comparison function
    sort(myArray, myArray + arraySize, descending);

    for (int i = 0; i < arraySize; i++)
    {
        cout << myArray[i] << ", ";
    }
    cout << endl;
}

void helloWorld(int num, int num2) {
    cout << "Hello World " << num << " " << num2 << endl;
}

bool descending(int a, int b) 
{
    return a > b;
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
