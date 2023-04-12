#pragma once
#include <algorithm>
#include <iostream>
template <class t>
class TemplatedStack
{
public:
	TemplatedStack() 
	{
		size = 2;
		count = 0;
		//array starts off with a default size of two
		underlyingArray = new t[size];
	}

	~TemplatedStack() 
	{
		//std::cout << "d" << std::endl;
		//deletes the array to prevent memory leaks
		delete[] underlyingArray;
		underlyingArray = nullptr;
	}

	TemplatedStack(const TemplatedStack& other) {
		//creates a new templated stack using the values taken from the other templated stack entered in the constructor
		size = other.size;
		count = other.count;
		underlyingArray = new t[size];
		//copies over the data from the other stack's array into the newly created one
		std::copy(other.underlyingArray, other.underlyingArray + other.size, underlyingArray);

		
		
	}

	TemplatedStack& operator= (const TemplatedStack& other)
	{
		//if the object is being set equal to itself
		if (this == &other) {
			return *this;
		}

		//if the array has been created, deletes it to prevent memory leaks
		if (underlyingArray != nullptr) {
			delete[] underlyingArray;
			underlyingArray = nullptr;
			size = 2;

		}
		//sets each value equal to those of the other templated stack 
		size = other.size;
		count = other.count;
		underlyingArray = new t[size];
		//populates this stack's array with data from the other stack's array
		std::copy(other.underlyingArray, other.underlyingArray + other.size, underlyingArray);

		return *this;
	}

	void Push(t item)
	{
		//checks when the array has been filled
		if (count == size) {
			
			//creates a new array with double the capacity
			t* temp = new t[size * 2];

			//copies over all the data currently stored in underlying array
			for (short i = 0; i < size; i++) {
				temp[i] = underlyingArray[i];
			}
			//updates the size variable
			size *= 2;
			delete[] underlyingArray;

			underlyingArray = temp;
			
			
			temp = nullptr;

		}

		//adds the new element to the array
		underlyingArray[count] = item;
		//increases the count
		count++;


	}

	t Pop() 
	{
		if (IsEmpty()) {
			//returns null if the stack is empty
			return NULL;
		}
		else {
			t temp = underlyingArray[count];
			//by reducing the count item stored in temp is in effect removed from the array because other methods can no longer access it
			count--;

			return temp;
		}

		
	}

	void Print() {

		//prints each element currently in the array, assuming that they are compatable with the << operator
		for (short i = 0; i < count; i++) 
		{
			std::cout << underlyingArray[i] << ", ";
		}
		//ends the line
		std::cout << std::endl;

	}

	int GetSize() 
	{
		//returns the number of elements currently in the underlying array
		return count;
	}

	//returns false if there any elements in the array otherwise returns true
	bool IsEmpty() {
		if (count != 0) {
			return false;
		}
		else {
			return true;
		}
	}

private:
	//total size of the current array
	int size;
	//number of items in the stack
	int count;

	t* underlyingArray;
};

