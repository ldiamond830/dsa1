#pragma once
class GamePiece
{
public:
	GamePiece();
	GamePiece(int _xPos, int _yPos, const char* _pieceName);

	virtual void Print();

	~GamePiece();

protected:
	int xPos;
	int yPos;
	char* pieceName;



};

