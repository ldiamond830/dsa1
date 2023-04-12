// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Person.h"
#include "SmartPersonPointer.h"
#include "SmartPointer.h"
#include <memory>
using namespace std;

void wrapper();

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks()) {
		cout << "leak" << endl;
	}

}

void wrapper() {
	//Person* pPtr = new Person();
	//pPtr->PrintName();

	SmartPersonPointer spPtr = SmartPersonPointer(new Person());
	spPtr->PrintName();

	SmartPointer<int> iPtr = SmartPointer<int>(new int(5));

	unique_ptr<int> uiPtr = unique_ptr<int>(new int(10));
	cout << *uiPtr << endl;

	//shared pointers can have multiple pointers pointing at the same object without causing an error when they are deleted
	shared_ptr<Person> sharedPersonPtr = shared_ptr<Person>(new Person());


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
