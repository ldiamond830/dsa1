#pragma once
#include <Box2D/Box2D.h>
//method declarations

void display(float, float, b2Vec2);

void applyForces(b2Body* player, int* moveCount, float dt);

int randomRange(float, float);

float returnX(float xCord);

float returnY(float yCord);