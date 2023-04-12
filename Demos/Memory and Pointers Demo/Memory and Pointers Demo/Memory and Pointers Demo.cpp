// Memory and Pointers Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

void passByValue(int);
void passByReference(int*);
void intoFunction(int[], int);

int main()
{
    //Stack variable 
    //uses 4 bytes to store '10'
    int myInteger = 10;
    cout << myInteger << endl;

    //prints spot in memory where "10" is stored
    cout << &myInteger << endl;

    int* myIntPointer = &myInteger;
    cout << myIntPointer << endl;
    //dereference opperater * prints stored value
    cout << *myIntPointer << endl;

    int one = 100;
    int two = 200;

    passByValue(one);
    //prints 100
    cout << one << endl;
    //prints 10
    passByReference(&two);
    cout << two << endl;

    two = 200;
    int* intTwoPointer = &two;
    passByReference(intTwoPointer);
    //prints 10
    cout << two << endl;

    int myArray[5] = { 1, 2, 3, 4, 5 }; 
    //4 bytes apart
    int* arr0 = &myArray[0];
    int* arr1 = &myArray[1];
    cout << "Value of arr0: " << arr0 << endl;
    cout<< "Value of arr1: " << arr1 << endl;
    //sets the value of arr0 to that of arr1 by increasing the address by 4 bytes
    //arr0 += 1;
    //cout << arr0;

    for (int i = 0; i < 5; i++) {
        cout << *arr0 << endl;
        arr0++;
    }

    //start of more pointers demo in mycourses
       myInteger = 40;
    int* myIntPtr = &myInteger;
    //would delete myInteger but not the arrow pointing to the location in myIntPtr, but this can't be done since ints are stored on the stack and can't be deleted
    //delete myIntPtr;
    //resets the pointer to point a default position
    myIntPtr = nullptr;

    //value 20 is on the heap
    int* myHeapIntPtr = new int(20);
    //prints the value
    cout << *myHeapIntPtr << endl;
    //changes value
    *myHeapIntPtr = 40;

    int* otherPtr;
    //otherPtr stores the same address as myHeapIntPtr, doesn't point to the pointer
    otherPtr = myHeapIntPtr;
    cout << *otherPtr << endl;

    //goes to the location on the heap and deletes the variable held there to free up memory
    delete myHeapIntPtr;
    myHeapIntPtr = nullptr;
    
    //delete otherPtr creates and error since the value was already deleted when delete myHJeapIntPtr was called
    otherPtr = nullptr;


    const int heapArraySize = 10;
    
    int* myHeapArray = new int[heapArraySize] {1, 2, 3};
    int stackArray[5] = { 1,2,3,4,5 }; // array variables are basically just pointers
    for (int i = 0; i < heapArraySize; i++) {
        //square bracket syntax works with pointers because arrays are built using pointers
        cout << myHeapArray[i] << ",";
        
    }
    cout << endl;

    //both work
    intoFunction(myHeapArray, heapArraySize);
    intoFunction(stackArray, 5);


    int* end = myHeapArray + heapArraySize;
    //pointer i contains a memory address which is just a number adn continues till that address number is equal to the end memeory address
    for (int* i = myHeapArray; i < end; i++) {
        cout << *i << ", ";
    }


    cout << endl;
    //don't delete because end is pointing at the address just outside of the array which could be anything
    end = nullptr;

    //better version because end is deleted when it goes out of scope, no nullptr or deletion required required 
    for (int* i = myHeapArray, int* end = myHeapArray + heapArraySize; i < end; i++) {
        cout << *i << ", ";
    }
    cout << endl;

    delete[] myHeapArray;
    myHeapArray = nullptr;

    //checks if there are any memory leaks while print the specific leak to the output window
    if (_CrtDumpMemoryLeaks()) {
        cout << "LEAKS" << endl;
    }
}

void passByValue(int x) 
{
    x = 10;
}
void passByReference(int* xPtr) 
{
    //takes in address of variable, goes to that address and puts in the number ten as its value
    *xPtr = 10;
}

void intoFunction(int array[], int size) {
    for (int i = 0; i <size; i++) {
        //square bracket syntax works with pointers because arrays are built using pointers
        cout << array[i] << ",";
        //same with different syntax
        //pointer goes to first location in the array and then increments by i 
        //cout << *(array + i) << ",";

    }
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
