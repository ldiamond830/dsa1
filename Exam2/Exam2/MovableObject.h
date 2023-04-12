#pragma once
 class MovableObject
{
protected:
	int xPosition;
	int yPosition;
public:
	//needs a virtual destructor in order to have the Ogre destructor override it
	virtual ~MovableObject();
	//methods
	void SetPosition(int x, int y);
	virtual void Display();
};

