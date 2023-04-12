#pragma once
#include <string>

class Player
{
	private: 
		short invSize;
		short* inventory;
		std::string name;


	public:
		//default constructor
		Player();
		//destructor
		~Player();

		void PrintInventory();

};

