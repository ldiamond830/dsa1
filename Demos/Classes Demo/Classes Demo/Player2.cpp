#include "Player2.h"
#include<iostream>;
using namespace std;


//calls the gamePiece default constructor to set other fields, can also use param constrcutor just put in values
Player2::Player2() : GamePiece()
{
	cout << "Player2 default constructor" << endl;
	experience = 0;
}

//passes down parameteres from the player2 constructor into the GamePiece constructor
Player2::Player2(int _xPos, int _yPos, const char* _pieceName, int _xp) : GamePiece(_xPos, _yPos, _pieceName)
{
	cout << "Player2 param constructor" << endl;
	experience = _xp;
}

Player2::~Player2()
{
	cout << "Player2 destructor for " << pieceName << endl;
}

void Player2::Print()
{
	GamePiece::Print();
	cout << " Experience: " << experience << endl;
}
