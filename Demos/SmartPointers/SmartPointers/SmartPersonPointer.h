#pragma once
#include "Person.h"
class SmartPersonPointer
{
public:
	SmartPersonPointer(Person* _ptr = nullptr);
	~SmartPersonPointer();

	Person& operator *();
	Person* operator ->();
private:
	Person* ptr;
};

