// PE6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;
void generateRandom(int);
char* reverseString(char[]);

int main()
{
    generateRandom(30);

    cout << "Input a string" << endl;
    char userInput[256];
    cin >> userInput;
    cout << reverseString(userInput);
}

void generateRandom(int numberOfRandoms) 
{
    srand(time(NULL));
    
    for (int i = 0; i < numberOfRandoms; i++) 
    {
         int random = rand();
        cout << "Random " << i << ": " << random << endl;
    }
}

char* reverseString(char inputString[])
{
    char newString[256] = "";
    int length = strlen(inputString);
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];
        newString[length - i] = c;
    }
    strcpy_s(inputString, 128, newString);
    return inputString;
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
