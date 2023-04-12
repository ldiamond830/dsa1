#pragma once
#include "GamePiece.h"

class Player2 : public GamePiece
{
public:
	Player2();
	Player2(int _xPos, int _yPos, const char* _pieceName, int _xp);

	~Player2();

	void Print() override;

private:
	int experience;
};

