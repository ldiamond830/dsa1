// PE8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void changeVariable(int);
void changePointer(int*);
int getLengthArray(int[]);
int getLengthPointer(int*);
int* createStackArray();
int* createHeapArray(int);
int main()
{
	int x = 10;
	int y = x << 2;
	
	


	//part 1
	int part1Int = 5;
	cout << "Initial value is " << part1Int << endl;;

	changeVariable(part1Int);
	//variable is still equal to 5 outside of the fucntion
	cout << "value is currently " << part1Int << endl;

	changePointer(&part1Int);
	//function changed the value of the variable to be 20 even outside of it's own scope
	cout << "value is currently " << part1Int << endl;


	//part 2
	int array[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1 };
	int* arrayPointer = array;

	//both print same value
	cout << "Array lenght is " << getLengthArray(arrayPointer) << endl;
	cout << "Array length form pointer is " << getLengthPointer(arrayPointer);

	//part 3 
	//because the array is stored on the stack when the scope of the function ends the memory holding it is overwritten and other random values are stored in it's place
	int* stackPointer = createStackArray();
	int* heapPointer = createHeapArray(5);

	for (int i = 0; i < 5; i++)
	{
		cout << *stackPointer << ", ";
		stackPointer++;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *heapPointer << ", ";
		heapPointer++;
	}

	//clears out memory leak
	delete arrayPointer;
	arrayPointer = nullptr;
	delete heapPointer;
	heapPointer = nullptr;
	cout << endl;
}

void changeVariable(int variable) 
{
	variable += 10;
	cout << "Inside changeVariable: variable is now equal to " << variable << endl;
}

void changePointer(int* pointer) 
{
	*pointer += 15;
	cout << "Inside changePointer variable is now equal to " << *pointer << endl;
}

int getLengthArray(int array[]) 
{
	int size = 0;
	bool keepLooping = true;

	while (keepLooping) 
	{
		if (*array == -1) 
		{
			//ends the loop
			keepLooping = false;
			//skips the size++ statement so the method doesn't count the terminator
			continue;
		}
		//goes to next spot in memory
		array++;
		//increments value
		size++;
	}

	return size;
}

int getLengthPointer(int* pointer) 
{
	int size = 0;
	bool keepLooping = true;

	while (keepLooping)
	{
		if (*pointer == -1)
		{
			//ends the loop
			keepLooping = false;
			//skips the size++ statement so the method doesn't count the terminator
			continue;
		}
		//goes to next spot in memory
		pointer++;
		//increments value
		size++;
	}
	return size;
}

int* createStackArray() 
{
	//creates an array on the stack
	int stackArray[5] = { 1, 2, 3, 4, 5 };
	return stackArray;
}
int* createHeapArray(int size) {
	//uses new keyword to make array on the stack
	int* heapArray = new int[size];
	//populates array
	for (int i = 0; i < size; i++) {
		//starts at 1 rather than zero
		heapArray[i] = i +1;
	}

	return heapArray;
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
