#pragma once
class PointSystem
{
private:
	
	int points;
	PointSystem();

public:
	static PointSystem* GetInstance();
	void AddPoints(int _changeInPoints);
	void PrintPointTotal();
};

