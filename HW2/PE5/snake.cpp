#include "snake.h"
#include <iostream>
#include <conio.h>
#include <Box2D/Box2D.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

//prints the position of the target and player
void display(float x, float y, b2Vec2 target) {
	
	cout << "Target X: " << target.x << " Target Y: " << target.y<< "	";
	cout << "	Player - ";
	cout << "(" << x << ", " << y << ")" << endl;
}

//checks if a key is being press and if it is one of the WASD movement keys increases the moves counter and applies a force to the player
void applyForces(b2Body* player, int* moveCount, float dt) {
	if (_kbhit()) 
	{
		
		char input = _getch();

		switch (input)
		{
		case 'w':
			//each force is scaled by deltaTime so that the speed of the player doesn't vary based on framerate
			player->ApplyForceToCenter(b2Vec2(0,110000000 * dt), true);
			*moveCount += 1;
			break;
		case 'a':
			player->ApplyForceToCenter(b2Vec2(-1500000 * dt, 0), true);
			*moveCount += 1;
			break;
		case 's':
			player->ApplyForceToCenter(b2Vec2(0, -110000000 * dt), true);
			*moveCount += 1;
			break;
		case 'd':
			player->ApplyForceToCenter(b2Vec2(1500000 * dt, 0), true);
			*moveCount += 1;
			break;

		default:
			//does nothing if the player is pressing any other key
			break;
		}
	}
}

//finds a random value between 2 numbers
int randomRange(float max, float min) 
{
	int temp = (max * 2) + 1;
	float random;

	//check for negative ranges
	if (min > 0) {
		random = (rand() % temp) - min;
	}
	else {
		random = (rand() % temp) + min;
	}
	

	return (int)random;
}