// HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemplatedStack.h"

void wrapper();
int main()
{
    
    wrapper();

    if (_CrtDumpMemoryLeaks()) {
        std::cout << "leaks";
    }

}

void wrapper() 
{
    //testing a stack using ints
    TemplatedStack<int> testInt = TemplatedStack<int>();
    testInt.Push(5);
    testInt.Push(10);
    testInt.Push(15);
    testInt.Push(20);
    testInt.Push(25);
    testInt.Print();
    testInt.Pop();
    testInt.Print();

    //testing a stack using chars
    TemplatedStack<char> testChar = TemplatedStack<char>();
    testChar.Push('a');
    testChar.Push('b');
    testChar.Push('c');
    testChar.Print();
    testChar.Pop();
    testChar.Pop();
    testChar.Print();

    //testing a stack using chars
    TemplatedStack<double> testDouble = TemplatedStack<double>();
    testDouble.Push(0.1);
    testDouble.Push(0.2);
    testDouble.Push(0.3);
    testDouble.Print();
    testDouble.Pop();
    testDouble.Print();


    //testing copy constructor
    TemplatedStack<int> intCopy = TemplatedStack<int>(testInt);
    intCopy.Print();
    intCopy.Pop();
    intCopy.Pop();
    intCopy.Print();
    //testing = operator
    intCopy = testInt;
    intCopy.Print();
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
