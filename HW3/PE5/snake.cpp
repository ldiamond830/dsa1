#include "snake.h"
#include <iostream>
#include <conio.h>
#include <Box2D/Box2D.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

//prints the position of the target and player
void display(float x, float y, b2Vec2 target) {
	
	cout << "Target X: " << target.x << " Target Y: " << target.y<< "	";
	cout << "	Player - ";
	cout << "(" << x << ", " << y << ")" << endl;
}

//checks if a key is being press and if it is one of the WASD movement keys increases the moves counter and applies a force to the player
void applyForces(b2Body* player, int* moveCount, float dt) {

	//WASD each apply a force in their respective direction and incriment the move count
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		player->ApplyForceToCenter(b2Vec2(0, 110000 * dt), true);
		*moveCount += 1;

	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player->ApplyForceToCenter(b2Vec2(-20000 * dt, 0), true);
		*moveCount += 1;

	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		player->ApplyForceToCenter(b2Vec2(0, -110000 * dt), true);
		*moveCount += 1;

	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player->ApplyForceToCenter(b2Vec2(20000 * dt, 0), true);
		*moveCount += 1;

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
//converts box2d coordinates to sfml window coordinates on the x axis
float returnX(float xCord)
{
	xCord += 10;
	xCord *= 40;
	return xCord;
}

//converts box2d coordinates to sfml window coordinates on the y axis
float returnY(float yCord)
{
	yCord -= 10;
	yCord *= -30;
	return yCord;
}
