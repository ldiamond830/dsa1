// BasicSyntaxDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //<< adds content to the stream
    cout << "Hello World!" << endl << "Extra Stuff" << endl; //since \n is only the new line command on windows endl is used

    //making variables
    bool myBool = true;
    int myInt = 10;
    char myChar = 'W';
    float myFloat = 100.001f;
    double myDouble = 200.002;

    //prints no because 100.001 and 100.001f are different
    if (myFloat == 100.001) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    //long = 4 bytes = 32 bits
    //short = 2 bytes = 16 bytes
    //int = 4 bytes = 32 bits meaning that long is basically useless
    long int myLong = 10000000000000000;
    int uselessLong = 10000000000000000;
    short int myShort = 3000;

    int thisInt = 5;
    //is equalvalent of
    signed long int sameInt = 5;

    unsigned int unsignedInt = -5; //returns 4294967291 because the sign makes the highest power of 2 in binary a 1 which the unsigned int doesn't interperate
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
