#pragma once
#include "Sorcerer.h"
#include "Cleric.h"
#include <string>

class Multiclass : private Sorcerer, private Cleric 
{
public:
	Multiclass();
	Multiclass(int _xPos, int _yPos, std::string _name, std::string _deity);
	~Multiclass();

	void PrintData() override;
};

