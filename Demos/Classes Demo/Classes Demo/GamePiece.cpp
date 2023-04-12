#include "GamePiece.h"
#include <cstring>
#include <iostream>
using namespace std;

GamePiece::GamePiece()
{
	cout << "gamePiece default constructor" << endl;
	xPos = 0;
	yPos = 0;
	pieceName = new char[6]{ "Piece" };
	
}

GamePiece::GamePiece(int _xPos, int _yPos, const char* _pieceName)
{
	cout << "gamePiece param constructor" << endl;
	xPos = _xPos;
	yPos = _yPos;
	
	int nameSize = strlen(_pieceName) + 1;
	pieceName = new char[nameSize];
	strcpy_s(pieceName, nameSize, _pieceName);

}

void GamePiece::Print()
{
	cout << endl;
	cout << "Name: " << pieceName;
	cout << " Position: (" << xPos << ", " << yPos <<")" << endl;
}

GamePiece::~GamePiece()
{
	cout << "gamePiece Destructor for "<< pieceName << endl;
	delete[] pieceName;
	pieceName = nullptr;
}
