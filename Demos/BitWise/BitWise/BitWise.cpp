// BitWise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <time.h>
using namespace std;

void printTwoShorts(short, short);
void printOneShort(short);
bool resolveCollision(short objectMask, short collsionLayer);

int main()
{
    short a = 0b11110000;
    short b = 0b10101010;

    //Bitwise AND
    printTwoShorts(a, b);

    short resultOfAND = a & b;
    cout << "Result of &                            Binary: ";
    cout << bitset <8>(resultOfAND) << endl;


    //Bitwise OR
    printTwoShorts(a, b);

    short resultOfOR = a | b;
    cout << "Result of |                            Binary: ";
    cout << bitset <8>(resultOfOR) << endl;

    //Bitwise XOR
    //XOR - exclusive or, returns true when inputs are different
    printTwoShorts(a, b);

    short resultOfXOR = a ^ b;
    cout << "Result of ^                            Binary: ";
    cout << bitset <8>(resultOfXOR) << endl;


    printOneShort(a);
    //complement, inverts every bit
    short resultOfComp = ~a;
    cout << "Result of ~                            Binary: ";
    cout << bitset <16>(resultOfComp) << endl;

    printOneShort(a);
    //Left Shift
    short resultOfLShift = a << 2; //multiplies number by 2 this many times
    cout << "Result of LSHIFT          Decimal: " << resultOfLShift;
    cout << " Binary: ";
    cout << bitset <16>(resultOfLShift) << endl;

    printOneShort(a);
    //Right Shift
    short resultOfRShift = a >> 1; //divides number by 2 this many times
    cout << "Result of RSHIFT          Decimal: " << resultOfRShift;
    cout << " Binary: ";
    cout << bitset <16>(resultOfRShift) << endl;

    //praticle examples
    //XOR swap
    short test1 = 0b11001100; // 204
    short test2 = 0b00110011; //51
    cout << test1 << "   " << test2 << endl;
    test1 = test1 ^ test2;
    //test1 = 0b1111111
    test2 = test1 ^ test2;
    //test2 = 0b11001100
    test1 = test1 ^ test2;
    //test1 = 0b00110011
    cout << test1 << "   " << test2 << endl;

    char myChar = 'A';
    char otherChar = 'B';
    cout << myChar << "    " << otherChar << endl;
    myChar = myChar ^ otherChar;
    otherChar = myChar ^ otherChar;
    myChar = myChar ^ otherChar;
    cout << myChar << "    " << otherChar << endl;

    //layers
    short bulletLayer = 0b0001;
    short playerLayer = 0b0010;
    short platfoLayer = 0b0100;
    short   wallLayer = 0b1000;

    //Masks
   //have 1s in the column of layers they interact with
    short  bulletMask = 0b0011;
    short  playerMask = 0b1111;
    short platforMask = 0b0010;
    short    wallMask = 0b0010;

    cout << "Bullet vs Bullet: " << resolveCollision(bulletMask, bulletLayer) << endl;
    cout << "Bullet vs Player: " << resolveCollision(bulletMask, playerLayer) << endl;
    cout << "Bullet vs Platform: " << resolveCollision(bulletMask, platfoLayer) << endl;
    cout << "Bullet vs wall: " << resolveCollision(bulletMask, wallLayer) << endl << endl;


    //new demo
    //inserts an unsiged int as a new random seed
    srand(30); // constant
    srand(time(NULL)); //uses the time as a seed, changes every millisecond
    cout << rand() << endl;
    //rand ranges from 0 to RAND_MAX'
    


    
}

bool resolveCollision(short objectMask, short collisionLayer) {
    //bulletLayer = 0001
    //playerMask  = 1111
    //AND           0001

    //bulletLayer = 0001
    //wallMask    = 0010
    //AND           0000
    
    //returns a short but in c++ any no zero number returns as true
    return objectMask & collisionLayer;
}

void printTwoShorts(short a, short b) 
{
    cout << endl;
    //20 spaces
    cout << "Short A                   Decimal: ";
    cout << a << " Binary: " << bitset<8>(a) << endl;

    cout << "Short B                   Decimal: ";
    cout << b << " Binary: " << bitset<8>(b) << endl;

}
void printOneShort(short a) 
{
    cout << endl;
    //20 spaces
    cout << "Short A                   Decimal: ";
    cout << a << " Binary: " << bitset<16>(a) << endl;
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
